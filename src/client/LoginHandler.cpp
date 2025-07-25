#include "LoginHandler.h"
#include "PasswordManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

LoginHandler::LoginHandler(std::string uname, std::string pwd)
	: Personal("",uname, pwd, "", "", "") {}

bool LoginHandler::loginUser() {
	bool loginsucess = true;
	std::ifstream in("data/users.txt");
	std::string line;
	std::string hashedInputPwd = PasswordManager::hashPassword(password);
	while (getline(in, line)) {
		std::istringstream iss(line);
		std::string nm, u, p, mail, ph, addr;
		iss >> nm >> u >> p >> mail >> ph >> addr;
		if (u == username && p == hashedInputPwd) {
			std::cout << "Login Successful! Welcome, " << u << "\n";
			return true;
			break;
		}
	}
	std::cout << "Invalid Credentials.\n";
	return false;

	std::ofstream logFile("data/logs/loginlog.txt", std::ios::app);
	if (logFile.is_open()) {
		std::time_t now = std::time(nullptr);
		char* dt = std::ctime(&now);
		dt[strlen(dt) - 1] = '\0'; // Remove newline character
		logFile << dt << " - Username: " << username
			<< " - Status: " << (loginsucess ? "Success" : "Failure") << "\n";
		logFile.close();
	}
	else {
		std::cerr << "Unable to open log file." << std::endl;
	}

	if (!loginsucess) {
		std::cout << "Invalid Credentials.\n";
	}

	return loginsucess;
};

//#include "LoginHandler.h"
//#include <iostream>
//#include <fstream>
//#include <sstream>
//
//using namespace std;
//
//LoginHandler::LoginHandler(string username, string password)
//    : Personal("", username, password, "", "", "") {}
//
//bool LoginHandler::loginUser() {
//    ifstream file("data/users.txt");
//    string line;
//    while (getline(file, line)) {
//        string user, pass;
//        stringstream ss(line);
//        getline(ss, user, '|');
//        getline(ss, pass);
//        if (user == getUsername() && pass == getPassword()) {
//            cout << "Login successful.\n";
//            return true;
//        }
//    }
//    cout << "Invalid credentials.\n";
//    return false;
//}

//#include "LoginHandler.h"
//#include"personal.h"
//#include <fstream>
//#include <sstream>
//#include <iostream>
//
//LoginHandler::LoginHandler(std::string uname, std::string pwd)
//    : Personal(uname, pwd, "", "", "", "") {}
//
//bool LoginHandler::authenticateFromFile(const std::string& filename) {
//    std::ifstream inFile(filename);
//    if (!inFile) {
//        std::cout << "❌ Could not open file for reading.\n";
//        return false;
//    }
//
//    std::string line;
//    while (getline(inFile, line)) {
//        std::stringstream ss(line);
//        std::string fileUsername, filePassword;
//        getline(ss, fileUsername, '|');
//        getline(ss, filePassword, '|');
//
//        if (fileUsername == username && filePassword == password) {
//            std::cout << "Login successful.\n";
//            return true;
//        }
//    }
//
//    std::cout << "Invalid username or password.\n";
//    return false;
//}
