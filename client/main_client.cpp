/*#include "AuthClient.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    AuthClient auth;
    int choice;
    string username, password;

    do {
        cout << "\n=== CloudVault Client Menu ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) 
        {
        case 1:

            cout << "Enter new username: ";
            getline(cin, username);
            cout << "Enter new password: ";
            getline(cin, password);
          
          
            auth.registerUser(username,password);
            break;

        case 2:
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);

            if (auth.login(username, password)) {
                cout << "Welcome, " << username << "!\n";
               
            }
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option \n";
        }

    } while (choice != 3);

    return 0;
}
*/

#include "AuthClient.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    AuthClient auth;
    int choice;
    string username, password, email, phone, address, name;

    do {
        cout << "\n=== CloudVault Client Menu ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // to clear newline

        switch (choice) {
        case 1:
            cout << "Enter full name: ";
            getline(cin, name);
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            cout << "Enter email: ";
            getline(cin, email);
            cout << "Enter phone number: ";
            getline(cin, phone);
            cout << "Enter address: ";
            getline(cin, address);

            auth.registerUser(username, password, email, address, phone, name);
            break;

        case 2:
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);

            if (auth.login(username, password)) {
                cout << "Welcome, " << username << "!\n";
            }
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option\n";
        }

    } while (choice != 3);

    return 0;
}
