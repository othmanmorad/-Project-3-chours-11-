#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"	
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
using namespace std;
class clsMainScreen : protected clsScreen
{

private:

	enum enMainMenuOptions { enShowClientList = 1, enAddNewClient = 2, enDeleteClient = 3,
		
		enUpdateClient = 4, enFindClient = 5, enShowTransactionsMenue = 6, enManageUsers = 7, enExit = 8	
	};


	static short _ReadMainMenuOption()
	{
		cout << "\nChoose what do you want to do? [1-8] : ";

		
			short Choice =clsInputValidate::ReadShortNumberBetween(1, 8," Enter Number Between [1-8]");

			return Choice;
	}

	static void _GoBackToMainMenu()
	{
		cout <<setw(37)<<left <<"\nPress any key to go back to Main Menu...";
		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowClientListScreen()
	{
		
		clsClientListScreen::ShowClientsList();
	}


	static void _ShowAddNewClientScreen()
	{
		//cout << setw(37) << left << "\nAdd Client Screen Will be here ...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();

	}


	static void _ShowDeleteClientScreen()
	{
		//cout << setw(37) << left << "\nDelete Client Screen Will be here ...\n";
		clsDeleteClientScreen::ShowDeletClientScreen();

		
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << setw(37) << left << "\nUpdate Client Screen Will be here ...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << setw(37) << left << "\nFind Client Screen Will be here ...\n";

		clsFindClientScreen::ShowUpdateClientScreen();	
	}

	static void _ShowTransactionsScreen()
	{
		//cout << setw(37) << left << "\nTransactions Screen Will be here ...\n";
		clsTransactionsScreen::ShowTransactionsScreen();
	}

	static void _ShowManageUsersScreen()
	{
		cout << setw(37) << left << "\nManage Users Screen Will be here ...\n";
	}

	static void _ShowEndScreen()
	{
		cout << setw(37) << left << "\nEndScreen Will be here ...\n";
		
	}




	static enMainMenuOptions _PerfromMainMenuOption(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enShowClientList:

		{
			system("cls");
			_ShowClientListScreen();
			_GoBackToMainMenu();
			break;

		}

		case enAddNewClient:

		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;

		}


		case enDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		}


		case enUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;

		}
		case enFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		}
		case enShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionsScreen();
			_GoBackToMainMenu();
			break;

		}
		case enManageUsers:
		{
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;

		}
		case enExit:
		{
			system("cls");
			_ShowEndScreen();
			_GoBackToMainMenu();
			break;

		}

		
		}
		return MainMenuOption;
	}







public:

	static void ShowMainMenu()
	{
	
		system("cls");
		clsScreen::_DrawScreenHeader("\t\tMain Screen","Menu of the bank");
		cout <<setw(37)<<left<< "\n\t\t\t\t==========================================================\n";
		cout <<setw(37)<<left<< "\n\t\t\t\t\tWelcome To the Main Screen.\n";
		cout <<setw(37)<<left<< "\n\n\t\t\t\t\t[1]. Show Client List.";
	    cout <<setw(37)<<left<< "\n\n\t\t\t\t\t[2]. Add New Client.";
		cout <<setw(37)<<left<< "\n\n\t\t\t\t\t[3]. Delete Client.";
		cout <<setw(37)<<left<< "\n\n\t\t\t\t\t[4]. Update Client";
		cout <<setw(37)<<left<< "\n\n\t\t\t\t\t[5]. Find Client.";
		cout <<setw(37)<<left<< "\n\n\t\t\t\t\t[6]. Transactions .";
		cout <<setw(37)<<left<< "\n\n\t\t\t\t\t[7]. Manage User.";
		cout <<setw(37)<<left<< "\n\n\t\t\t\t\t[8]. Exit.\n";
		cout <<setw(37)<<left<< "\n\t\t\t\t==========================================================\n";
		_PerfromMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
	}						 
};

