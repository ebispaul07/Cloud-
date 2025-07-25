#include "RegisterHandler.h"
#include "UserValidator.h"
#include "PasswordManager.h"
#include <fstream>
#include <iostream>

RegisterHandler::RegisterHandler(std::string uname, std::string pword, std::string mail, std::string addr, std::string ph, std::string nm)
	: Personal(uname, pword, mail, addr, ph, nm) {}

void RegisterHandler::registerUser() {
	if (!UserValidator::isValidEmail(email) || !UserValidator::isValidPhone(phone)) {
		std::cout << "Invalid email or phone number.\n";
		return;
	}
	std::ofstream out("data/users.txt", std::ios::app);
	if (!out) {
		std::cerr << "Could not open user file.\n";
		return;
	}
	std::string hashedPwd = PasswordManager::hashPassword(password);
	out << username << " " << hashedPwd << " " << email << " " << phone << " " << address << " " << name << "\n";
	std::cout << "Registered Successfully!\n";
}

//#include "RegisterHandler.h"
//#include "UserValidator.h"
//#include "PasswordManager.h"
//#include <fstream>
//#include <iostream>
//
//RegisterHandler::RegisterHandler(std::string uname, std::string pwd, std::string mail, std::string addr, std::string ph, std::string fname)
//    : Personal(uname, pwd, fname, mail, ph, addr) {}  // Match constructor order in Personal
//
//void RegisterHandler::registerUser() {
//    if (!UserValidator::isValidEmail(email) || !UserValidator::isValidPhone(phoneNumber)) {
//        std::cout << "Invalid email or phone number.\n";
//        return;
//    }
//
//    std::ofstream out("data/users.txt", std::ios::app);
//    if (!out) {
//        std::cerr << "Could not open user file.\n";
//        return;
//    }
//
//    std::string hashedPwd = PasswordManager::hashPassword(password);
//    out << username << " " << hashedPwd << " " << email << " " << phoneNumber << " " << address << " " << fullName << "\n";
//    std::cout << "Registered Successfully!\n";
//}


//#include "RegisterHandler.h"
//#include"personal.h"
//#include <fstream>
//#include <iostream>
//
//RegisterHandler::RegisterHandler(std::string uname, std::string pwd, std::string fname,
//    std::string mail, std::string ph, std::string addr)
//    : Personal(uname, pwd, fname, mail, ph, addr) {}
//
//bool RegisterHandler::saveUserToFile(const std::string& filename) {
//    if (!UserValidator::isValidUsername(username) ||
//        !UserValidator::isValidPassword(password) ||
//        !UserValidator::isValidEmail(email) ||
//        !UserValidator::isValidPhone(phone)) {
//        std::cout << " Registration failed: Invalid input.\n";
//        return false;
//    }
//
//    std::ofstream outFile(filename, std::ios::app);
//    if (!outFile) {
//        std::cout << "Failed to open file for writing.\n";
//        return false;
//    }
//
//    outFile << username << "|" << password << "|" << fullName << "|"
//        << email << "|" << phone << "|" << address << "\n";
//
//    std::cout << "User registered successfully.\n";
//    return true;
//}
