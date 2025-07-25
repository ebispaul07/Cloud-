#include "MemberC/PermanentDeleteHandler.h"
#include <iostream>
#include <filesystem>

using namespace std;


void PermanentDeleteHandler::setUsername(string username) {
    this->username = username;
}

string PermanentDeleteHandler::getUsername() {
    return this->username;
}

void PermanentDeleteHandler::setFilename(string filename) {
    this->filename = filename;
}

string PermanentDeleteHandler::getFilename() {
    return this->filename;
}

// Main logic using internal members
void PermanentDeleteHandler::deletePermanently() {
    thread([=]() {
        lock_guard<mutex> lock(perMutex);

        string trashFile = "storage/" + username + "/trash/" + filename;

        cout << "Permanent Delete: " << trashFile << endl;

        if (!filesystem::exists(trashFile)) {
            cout << "File not found in trash!" << endl;
            return;
        }

        try {
            filesystem::remove(trashFile);
            cout << "File Deleted Permanently" << endl;
        }
        catch (const exception& e) {
            cerr << "Deletion error: " << e.what() << endl;
        }

        }).detach();  // Thread runs independently
}


void PermanentDeleteHandler::deletePermanently(const string& username, const string& filename) {
    setUsername(username);
    setFilename(filename);
    deletePermanently();  // Use internal
}
