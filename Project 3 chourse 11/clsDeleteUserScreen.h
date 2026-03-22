#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUser.h"
using namespace std;
class clsDeleteUserScreen : protected clsScreen
{


private:
    static void _Print(clsUser User)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions     : " << User.Permissions;
        cout << "\n___________________\n";

    }


public:



    static void ShowDeletUserScreen()
    {
        _DrawScreenHeader("\t\tDelete User Screen", "Delete User From the System");

        string UserName = "";

        cout << "Enter Account Number : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "User Name was not found , enter anoter one.";
            UserName = clsInputValidate::ReadString();
        }


        clsUser User = clsUser::Find(UserName);

        _Print(User);

        cout << "Are you sure you want to delete this account ? y/n : ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nAccount Deleted Successfully.\n";
            }
            else
            {
                cout << "\nFailed to Delete Account.\n";
            }

        }



    }


};
