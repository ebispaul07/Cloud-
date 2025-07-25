#include "MemberC/DeleteHandler.h"
#include <iostream>
#include <filesystem>

using namespace std;

void DeleteHandler::setUsername(string username) {
    this->username = username;
}

string DeleteHandler::getUsername() {
    return this->username;
}

void DeleteHandler::setFilename(string filename) {
    this->filename = filename;
}

string DeleteHandler::getFilename() {
    return this->filename;
}

void DeleteHandler::deleteFile() {
    thread([=]() {
        lock_guard<mutex> lock(deleteMutex);

        string srcPath = "storage/" + username + "/" + filename;
        string trashPath = "storage/" + username + "/trash/";

        cout << "Deleting File: " << filename << " from user: " << username << endl;

        if (!filesystem::exists(srcPath)) {
            cout << "File does not exist" << endl;
            return;
        }

        try {
            filesystem::create_directories(trashPath);
            filesystem::rename(srcPath, trashPath + filename);
            cout << "Moved to trash successfully" << endl;
        }
        catch (const exception& e) {
            cerr << "Exception: " << e.what() << endl;
        }
        }).detach();
}

void DeleteHandler::deleteFile(const string& username, const string& filename) {
    setUsername(username);
    setFilename(filename);
    deleteFile();
}
