#pragma once
#pragma once
#include <iostream>
#include <string>
#include"clsDate.h"
#include"Global.h"

using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle="")
	{
		cout << "\n\t\t\t\t\t----------------------------------------------";
		cout << "\n\t\t\t\t\t" << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t\t\t" << SubTitle;
		}
		cout << "\n\t\t\t\t\t----------------------------------------------\n";

		cout << "\n\t\t\t\t\tCurrent User: " << CurrentUser.FullName() << " (" << CurrentUser.UserName << ")";
		cout << "\n\t\t\t\t\tDate: "<<clsDate::DateToString(clsDate());

		/* or you can write it like this
		string Date = clsDate::GetSystemDate().DateToString();
		cout << "\n\t\t\t\t\tDate: " << Date << endl;
		*/
		
	}
	

	static bool _CheckAccessRights(clsUser::enPermissions Permissions)
	{
		if (!CurrentUser.CheckAccessPermissions(Permissions) )
		{
			cout << "===================================================================================================\n";
			cout << setw(37) << left << "\nAccess Denied! contact your Admin \n";
			cout << setw(37) << left << "\nYou don't have permissions to access this screen\n";
			cout << "===================================================================================================\n";
			return false;
		}
		else
		{
			return true;
		}

	}
	
};

