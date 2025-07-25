#include "Personal.h"
#include <iostream>

Personal::Personal() {}

Personal::Personal(std::string uname, std::string pwd, std::string mail, std::string addr, std::string ph, std::string nm)
	: username(uname), password(pwd), email(mail), address(addr), phone(ph), name(nm) {}

void Personal::displayProfile() const {
	std::cout << "\nName: " << name << "\nEmail: " << email << "\nPhone: " << phone << "\nAddress: " << address << "\n";
}

std::string Personal::getUsername() const { return username; }
std::string Personal::getPassword() const { return password; }
std::string Personal::getEmail() const { return email; }
std::string Personal::getPhone() const { return phone; }

//#include<iostream>
//#include "Personal.h"
//
//// Constructor
//Personal::Personal(string uname, string pwd, string fname, string mail, string addr, string phone)
//    : username(uname), password(pwd), fullName(fname), email(mail), address(addr), phoneNumber(phone) {}
//
//// Getters
//string Personal::getUsername() {
//    return username;
//}
//
//string Personal::getPassword() {
//    return password;
//}
//
//string Personal::getFullName() {
//    return fullName;
//}
//
//string Personal::getEmail() {
//    return email;
//}
//
//string Personal::getAddress() {
//    return address;
//}
//
//string Personal::getPhoneNumber() {
//    return phoneNumber;
//}
//
//// Setters
//void Personal::setUsername(string uname) {
//    username = uname;
//}
//
//void Personal::setPassword(string pwd) {
//    password = pwd;
//}
//
//void Personal::setFullName(string fname) {
//    fullName = fname;
//}
//
//void Personal::setEmail(string mail) {
//    email = mail;
//}
//
//void Personal::setAddress(string addr) {
//    address = addr;
//}
//
//void Personal::setPhoneNumber(string phone) {
//    phoneNumber = phone;
//}

//#include "Personal.h"
//
//Personal::Personal(std::string uname, std::string pwd, std::string fname,
//    std::string mail, std::string ph, std::string addr)
//    : username(uname), password(pwd), fullName(fname), email(mail), phone(ph), address(addr) {}
//
//std::string Personal::getUsername() { return username; }
//std::string Personal::getPassword() { return password; }
//std::string Personal::getFullName() { return fullName; }
//std::string Personal::getEmail() { return email; }
//std::string Personal::getPhone() { return phone; }
//std::string Personal::getAddress() { return address; }
