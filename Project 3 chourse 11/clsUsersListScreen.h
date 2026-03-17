#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include"clsUser.h"
#include"clsScreen.h"	

using namespace std;
class clsUsersListScreen : protected clsScreen
{
private:
	static void _PrintUserRecord(clsUser User)
	{
		cout<<"|  "<< setw(8)  << left << "\n_________________________________________________________________________________________________________________\n";
		cout<<"|  "<< setw(15) << left << User.UserName;
		cout<<"|  "<< setw(25) << left << User.FullName();
		cout<<"|  "<< setw(12) << left << User.Phone;
		cout<<"|  "<< setw(15) << left << User.Email;
		cout<<"|  "<< setw(15) << left << User.Password;
		cout<<"|  "<< setw(12) << left << User.Permission;
		cout<<"|  "<< endl;
	}

public:
	static void ShowUsersList()
	{
		vector<clsUser>vUsers = clsUser::GetUsersList();
		string Title = "\t  Users List Screen";
		string SubTitle = "\n\t\t\t\t\t\tUsers List (" + to_string(vUsers.size()) + ") User(s)\n";
		_DrawScreenHeader(Title, SubTitle);
		cout<< setw(8) << left << "\n_________________________________________________________________________________________________________________\n";
		cout<<"|  "<< setw(15) << left << "UserName";
		cout<<"|  "<< setw(25) << left << "FullName";
		cout<<"|  "<< setw(12) << left << "Phone";
		cout<<"|  "<< setw(15) << left << "Email";
		cout<<"|  "<< setw(15) << left << "Password";
		cout<<"|  "<< setw(12) << left << "Permission";
		cout << setw(8) << left << "\n_________________________________________________________________________________________________________________\n";
		if (vUsers.size() > 0)
		{
			for (clsUser User : vUsers)
			{
				_PrintUserRecord(User);
			}
			cout << setw(8) << left << "\n_________________________________________________________________________________________________________________\n";
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\tNo Users Available In the System !\n";
		}
	}
};

