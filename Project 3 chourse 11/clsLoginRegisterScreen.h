#pragma once
#include <iostream>
#include"clsMainScreen.h"
#include"clsUser.h"
using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
private:
	static void _PrintLoginRegisterRecord(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << "|  " << setw(8) << left << "\n_________________________________________________________________________________________________________________\n";
		cout << "|  " << setw(25) << left << LoginRegisterRecord.DateTime;
		cout << "|  " << setw(15) << left << LoginRegisterRecord.UserName;
		cout << "|  " << setw(15) << left << LoginRegisterRecord.Password;
		cout << "|  " << setw(12) << left << LoginRegisterRecord.Permissions;
		cout << "|  " << endl;
	}

public:
	static void ShowLoginRegisterScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pShowLogInRegister))
		{
			return;
		}
		vector<clsUser:: stLoginRegisterRecord>vLoginRegisterRecord = clsUser::GetLoginRegisterList();
		string Title = "\t  Login Register";
		string SubTitle = "\n\t\t\t\t\t\tUsers List (" + to_string(vLoginRegisterRecord.size()) + ") User(s)\n";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "\n_________________________________________________________________________________________________________________\n";
		cout << "|  " << setw(25) << left << "Date Time";
		cout << "|  " << setw(15) << left << "User Name";
		cout << "|  " << setw(15) << left << "Password";
		cout << "|  " << setw(12) << left << "Permission";
		cout << setw(8) << left << "\n_________________________________________________________________________________________________________________\n";
		if (vLoginRegisterRecord.size() > 0)
		{
			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
			{
				_PrintLoginRegisterRecord(Record);
			}
			cout << setw(8) << left << "\n_________________________________________________________________________________________________________________\n";
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\tNo Users Available In the System !\n";
		}
	}
};

