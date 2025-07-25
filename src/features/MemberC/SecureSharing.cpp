#include "MemberC/SecureSharing.h"
#include "MemberC/SecurityCheck.h"
#include <iostream>
#include <filesystem>

using namespace std;


void SecureSharing::setSender(string sender) {
    this->sender = sender;
}

string SecureSharing::getSender() {
    return this->sender;
}

void SecureSharing::setReceiver(string receiver) {
    this->receiver = receiver;
}

string SecureSharing::getReceiver() {
    return this->receiver;
}

void SecureSharing::setFilename(string filename) {
    this->filename = filename;
}

string SecureSharing::getFilename() {
    return this->filename;
}

bool SecureSharing::shareFile() {
    thread([=]() {
        lock_guard<mutex> lock(shareMutex);

        string senderPath = "storage/" + sender + "/" + filename;
        string receiverPath = "storage/" + receiver + "/inbox/";
        string sharedFileName = sender + "_" + filename;

        cout << "Secure Sharing from '" << sender << "' to '" << receiver << "'..." << endl;

        if (!SecurityCheck::isLoggedIn(sender)) {
            cout << "Sender must be logged in to share files." << endl;
            return;
        }

        if (!filesystem::exists("storage/" + receiver)) {
            cout << "Receiver not found." << endl;
            return;
        }

        if (!filesystem::exists(senderPath)) {
            cout << "File does not exist to share: " << senderPath << endl;
            return;
        }

        try {
            filesystem::create_directories(receiverPath);
            filesystem::copy_file(senderPath, receiverPath + sharedFileName, filesystem::copy_options::overwrite_existing);
            cout << "File shared securely to " << receiver << "'s inbox as '" << sharedFileName << "'" << endl;
        }
        catch (const exception& e) {
            cerr << "Error while sharing: " << e.what() << endl;
        }

        }).detach();

        return true;
}

bool SecureSharing::shareFile(const string& sender, const string& receiver, const string& filename) {
    setSender(sender);
    setReceiver(receiver);
    setFilename(filename);
    return shareFile();
}
