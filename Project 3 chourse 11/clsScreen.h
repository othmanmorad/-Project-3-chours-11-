#pragma once
#pragma once
#include <iostream>
#include <string>
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

