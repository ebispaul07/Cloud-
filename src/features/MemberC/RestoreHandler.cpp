#include "MemberC/RestoreHandler.h"
#include <iostream>
#include <filesystem>


using namespace std;


void RestoreHandler::setUsername(string username) {
    this->username = username;
}

string RestoreHandler::getUsername() {
    return this->username;
}

void RestoreHandler::setFilename(string filename) {
    this->filename = filename;
}

string RestoreHandler::getFilename() {
    return this->filename;
}


void RestoreHandler::restoreFile() {
    //for multiple restores
    thread([=]() {
        lock_guard<mutex> lock(restoreMutex);// used to prevent conflict

        string trashPath = "storage/" + username + "/trash/" + filename;

        string restorePath = "storage/" + username + "/" + filename;

        cout << "Restoring file: " << filename << " for user: " << username << endl;


        //check if the file exists in trash
        if (!filesystem::exists(trashPath)) {
            cout << "File not found in trash" << endl;
            return;
        }

        //it move file back to original location 
        try {
            filesystem::rename(trashPath, restorePath);
            cout << "File restored successfully" << endl;
        }
        catch (const exception& e) {
            cerr << "Exception during restore: " << e.what() << endl;
        }

        }).detach();  // it run independently and dont wait until the process completed
}


void RestoreHandler::restoreFile(const string& username, const string& filename) {
    setUsername(username);
    setFilename(filename);
    restoreFile();  // use class variables
}
