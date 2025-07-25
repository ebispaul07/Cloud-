#ifndef SECURE_SHARING_H
#define SECURE_SHARING_H

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include "base/ShareBase.h"


using namespace std;

class SecureSharing : public ShareBase {
private:
    string sender;
    string receiver;
    string filename;
    mutex shareMutex;

public:
    void setSender(string sender);
    string getSender();

    void setReceiver(string receiver);
    string getReceiver();

    void setFilename(string filename);
    string getFilename();

    bool shareFile();  // Uses class members
    bool shareFile(const string& sender, const string& receiver, const string& filename);  // Direct call
};

#endif
