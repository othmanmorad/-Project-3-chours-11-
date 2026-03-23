#pragma once
#include <iostream>
#include"clsMainScreen.h"
#include"clsUser.h"	
#include "clsScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{

private:
	static void _Login()
	{
		bool LoginFaild = false;

		string UserName, Password;

		do
		{

			if (LoginFaild)
			{
				cout << "\nLogin Faild, Try Again...\n";
			}
			cout << "\nPlease enter User Name: ";	
			cin >> UserName;
			cout << "\nPlease enter Password: ";
			cin >> Password;
		 CurrentUser = clsUser::Find(UserName, Password);

		 LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		clsMainScreen::ShowMainMenu();
	}




public:
	static void ShowLoginScreen()
	{
		system("cls");
		string Title = "\t\tLogin Screen";
		string SubTitle = "\n\t\t\t\t\t\tPlease Login First\n";
		_DrawScreenHeader(Title, SubTitle);
		_Login();
	}
};

