#pragma once
#ifndef LOGIN_HANDLER_H
#define LOGIN_HANDLER_H

#include "Personal.h"

class LoginHandler : public Personal {
public:
	LoginHandler(std::string uname, std::string pwd);
	bool loginUser();
};

#endif

//#pragma once
//#ifndef LOGINHANDLER_H
//#define LOGINHANDLER_H
//
//#include "Personal.h"
//
//class LoginHandler : public Personal {
//public:
//    LoginHandler(string username, string password);
//    bool loginUser();
//};
//
//#endif

//#ifndef LOGIN_HANDLER_H
//#define LOGIN_HANDLER_H
//
//#include "Personal.h"
//
//class LoginHandler : public Personal {
//public:
//    LoginHandler(std::string uname, std::string pwd);
//
//    bool authenticateFromFile(const std::string& filename);
//};
//
//#endif
