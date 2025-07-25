#include "SessionManager.h"
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void SessionManager::createSession(const string& username)
{
    ofstream file(sessionFile, ios::app);
    file << username << "\n";
}

void SessionManager::endSession(const string& username)
{
    ifstream infile(sessionFile);
    vector<string> users;
    string line;

    while (getline(infile, line))
    {
        if (line != username)
            users.push_back(line);
    }
    infile.close();

    ofstream outfile(sessionFile);
    for (const auto& u : users)
        outfile << u << "\n";
}

bool SessionManager::isUserLoggedIn(const string& username)
{
    ifstream file(sessionFile);
    string line;
    while (getline(file, line))
    {
        if (line == username)
            return true;
    }
    return false;
}

