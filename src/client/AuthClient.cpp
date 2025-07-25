//#include "AuthClient.h"
//#include <iostream>
//#include <fstream>
//#include <sstream>
//
//using namespace std;
//
//bool AuthClient::login(const string& username, const string& password)
//{
//	ifstream file("data/users.txt");
//	string line;
//	while (getline(file, line))
//	{
//		stringstream ss(line);
//		string user, pass;
//		getline(ss, user, '|');
//		getline(ss, pass);
//		if (user == username && pass == password)
//		{
//			cout << "Login successful.\n";
//			return true;
//		}
//	}
//	cout << "Invalid credentials.\n";
//	return false;
//}
//
//bool AuthClient::registerUser(const string& username, const string& password)
//{
//	ofstream file("data/users.txt", ios::app);
//	file << username << "|" << password << "\n";
//	cout << "Registration successful.\n";
//	return true;
//}
//
//void AuthClient::logout() 
//{
//	cout << "Logged out.\n";
//}


#include "AuthClient.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Constructor
AuthClient::AuthClient(const string& uname, const string& pword)
    : username(uname), password(pword) {}

// Setters
void AuthClient::setUsername(const string& uname) {
    username = uname;
}

void AuthClient::setPassword(const string& pword) {
    password = pword;
}

// Getters
string AuthClient::getUsername() const {
    return username;
}

string AuthClient::getPassword() const {
    return password;
}

// Register a new user (appends to file)
//// AuthClient.cpp
//void AuthClient::registerUser(const std::string& uname, const std::string& pwd, const std::string& email,
//    const std::string& address, const std::string& phone, const std::string& name)
//{
//    RegisterHandler reg(uname, pwd, email, address, phone, name);
//    reg.registerUser();
//}



 bool AuthClient:: registerUser(const std::string& uname, const std::string& pword, const std::string& email,
    const std::string& address, const std::string& phone, const std::string& name)
{
    
    ofstream file("data/users.txt", ios::app);
    if (!file.is_open()) {
        cerr << " Unable to open user file for registration.\n";
        return false;
    }
    file << name<<"|" << uname << "|" << pword << "|" << email << "|" << address << "|" << phone << "\n";
    cout << " Registration successful.\n";
    return true;
}

// Login by checking user credentials in file
 bool AuthClient::login(const string& uname, const string& pword) {
     ifstream file("data/users.txt");
     if (!file.is_open()) {
         cerr << "Unable to open user file for login.\n";
         return false;
     }

     string line;
     while (getline(file, line)) {
         stringstream ss(line);

         string id, file_username, file_password;

         getline(ss, id, '|');              
         getline(ss, file_username, '|');   
         getline(ss, file_password, '|');   

         if (file_username == uname && file_password == pword) {
             cout << " Login successful.\n";
             return true;
         }
     }

     cout << "❌ Invalid credentials.\n";
     return false;

 }

void AuthClient::logout() {
    cout << " Logged out: " << username << endl;
    username = "";
    password = "";
}