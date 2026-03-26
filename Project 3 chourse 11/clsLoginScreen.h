#pragma once
#include <iostream>
#include"clsMainScreen.h"
#include"clsUser.h"	
#include "clsScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{

private:
	static bool _Login()
	{
		bool LoginFaild = false;

		short FailedLoginCounter = 0;	
		string UserName, Password;

		
			do
			{

				if (LoginFaild)
				{
					FailedLoginCounter++;
					cout << "\nInvalid Username /Password!\n";
					cout << "\n You have " << 3 - FailedLoginCounter << " tries left\n";	

				}
				if (FailedLoginCounter == 3)
				{
					cout << "\nYou have entered wrong username/password for 3 times, the program will be closed\n";
					return false;
				}
				cout << "\nPlease enter User Name: ";
				cin >> UserName;
				cout << "\nPlease enter Password: ";
				cin >> Password;
				CurrentUser = clsUser::Find(UserName, Password);

				LoginFaild = CurrentUser.IsEmpty();

			} while (LoginFaild);

			CurrentUser.RegisterLogIn();	
			clsMainScreen::ShowMainMenu();
			return true;
	}




public:
	static bool ShowLoginScreen()
	{
		
			system("cls");
			string Title = "\t\tLogin Screen";
			string SubTitle = "\n\t\t\t\t\t\tPlease Login First\n";
			_DrawScreenHeader(Title, SubTitle);
			return _Login();
		
	}
};

