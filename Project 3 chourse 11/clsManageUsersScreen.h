#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsUsersListScreen.h"	
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"

using namespace std;
class clsManageUsersScreen : protected clsScreen
{
private:

	enum enManageUsersMenuOptions 
	{
		enListUsers = 1,
		enAddNewUser = 2, enDeleteUser = 3,
		enUpdateUser = 4,enFindUser = 5 ,enMainMenue = 6
	};

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "\n\t\t\t\tChoose what do you want to do? [1-6] : ";


		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, " Enter Number Between [1-4]");

		return Choice;
	}

	static void _ShowListUsersScreen()
	{
		//cout << setw(37) << left << "\nList Users Screen Will be here ...\n";
		clsUsersListScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << setw(37) << left << "\nAdd New User Screen Will be here ...\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << setw(37) << left << "\nDelete User Screen Will be here ...\n";
		clsDeleteUserScreen::ShowDeletUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		cout << setw(37) << left << "\nUpdate User Screen Will be here ...\n";
	}

	static void _ShowFindUserScreen()
	{
		cout << setw(37) << left << "\nFind User Screen Will be here ...\n";
	}

	static void _ShowMainMenuScreen()
	{
		cout << setw(37) << left << "\nMain Menu Screen Will be here ...\n";
	}

	static void _GoBackToManageUsersMenu()
	{
		cout << setw(37) << left << "\nPress any key to go back to Manage Users Menu...";
		system("pause>0");
		ShowManageUsersScreen();
	}

	static void _PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersMenuOption)
	{
		switch (ManageUsersMenuOption)
		{
		case enListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enMainMenue:
		{
			//do nothing just return to main menu
		}
		}
	}
	

	public:
		static void ShowManageUsersScreen()
		{
			system("cls");
			string Title = "\t  Manage Users Screen";
			string SubTitle = "\n\t\t\t\t\t\tManage Users Options Screen\n";
			_DrawScreenHeader(Title, SubTitle);
			cout << setw(37) << left << "\n\t\t\t\t==========================================================\n";
			cout << setw(37) << left << "\n\n\t\t\t\t\t[1]. List Users.";
			cout << setw(37) << left << "\n\n\t\t\t\t\t[2]. Add New User.";
			cout << setw(37) << left << "\n\n\t\t\t\t\t[3]. Delete User.";
			cout << setw(37) << left << "\n\n\t\t\t\t\t[4]. Update User.";
			cout << setw(37) << left << "\n\n\t\t\t\t\t[5]. Find User.";
			cout << setw(37) << left << "\n\n\t\t\t\t\t[6]. Main Menu.";
			cout << setw(37) << left << "\n\t\t\t\t==========================================================\n";
			_PerformManageUsersMenuOption((enManageUsersMenuOptions)_ReadMainMenuOption());
		}
};

