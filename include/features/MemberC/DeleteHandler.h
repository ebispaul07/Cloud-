#ifndef DELETE_HANDLER_H
#define DELETE_HANDLER_H

#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include "base/TrashBase.h"

using namespace std;

class DeleteHandler : public TrashBase {
private:
    string username;
    string filename;
    mutex deleteMutex;

public:
    void setUsername(string username);
    string getUsername();

    void setFilename(string filename);
    string getFilename();

    void deleteFile();
    void deleteFile(const string& username, const string& filename);
};

#endif


