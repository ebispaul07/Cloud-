#ifndef PERSONAL_H
#define PERSONAL_H

#include <string>

class Personal {
protected:
	std::string name;
	std::string username;
	std::string password;
	std::string email;
	std::string address;
	std::string phone;
public:
	Personal();
	Personal(std::string uname, std::string pwd, std::string mail, std::string addr, std::string ph, std::string nm);
	void displayProfile() const;
	std::string getUsername() const;
	std::string getPassword() const;
	std::string getEmail() const;
	std::string getPhone() const;
};

#endif



//#pragma once
//#ifndef PERSONAL_H
//#define PERSONAL_H
//
//#include<iostream>
//#include <string>
//using namespace std;
//
//class Personal {
//protected:
//    string username;
//    string password;
//    string fullName;
//    string email;
//    string address;
//    string phoneNumber;
//
//public:
//    Personal() = default;
//
//    Personal(string uname, string pwd, string fname, string mail, string addr, string phone);
//
//    void setUsername(string uname);
//    string getUsername();
//
//    void setPassword(string pwd);
//    string getPassword();
//
//    void setFullName(string fname);
//    string getFullName();
//
//    void setEmail(string mail);
//    string getEmail();
//
//    void setAddress(string addr);
//    string getAddress();
//
//    void setPhoneNumber(string phone);
//    string getPhoneNumber();
//};
//
//#endif

//#ifndef PERSONAL_H
//#define PERSONAL_H
//
//#include <string>
//
//class Personal {
//protected:
//    std::string username;
//    std::string password;
//    std::string fullName;
//    std::string email;
//    std::string phone;
//    std::string address;
//
//public:
//    Personal(std::string uname, std::string pwd, std::string fname,
//        std::string mail, std::string ph, std::string addr);
//
//    std::string getUsername();
//    std::string getPassword();
//    std::string getEmail();
//    std::string getPhone();
//    std::string getAddress();
//    std::string getFullName();
//};
//
//#endif
