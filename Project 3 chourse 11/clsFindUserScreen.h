#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;
class clsFindUserScreen : protected clsScreen
{
private:

   
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

   
public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t\tFind User Screen", "Find User Info");
        string UserName = "";

        cout << "Enter User Name : ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "User Name was not found , enter anoter one.";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::Find(UserName);

        if (!User.IsEmpty())
        {
			cout << "\nUser Found Successfully :-)\n";
        }
		else
		{
			cout << "\nUser was not found :-(";
		}
        _PrintUser(User);
    }

};
