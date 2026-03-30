#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsShowTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
using namespace std;
class clsTransactionsScreen : protected clsScreen	
{
private:

	enum enTransactionsMenuOptions { enDeposit = 1, enWithdraw = 2,
		enShowTotalBalance = 3,enTransfer=4,enTransferLogScreen=5 ,enShowMainMenue = 6 };

		static short _ReadMainMenuOption()
	{
		cout <<setw(37)<< left<<"\nChoose what do you want to do? [1-6] : ";


		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, " Enter Number Between [1-6]");

		return Choice;
	}

		static void _ShowDepositScreen()
		{
			//cout << setw(37) << left << "\nDeposit Screen Will be here ...\n";
			clsDepositScreen::ShowDepositScreen();
		}

		static void _ShowWithdrawScreen()
		{
			//cout << setw(37) << left << "\nWithdraw Screen Will be here ...\n";
			clsWithdrawScreen::ShowWithDrawScreen();
		}

		static void _ShowTotalBalanceScreen()
		{
			//cout << setw(37) << left << "\nTotal Balance Screen Will be here ...\n";
			clsShowTotalBalancesScreen::ShowClientsList();
		}

		static void _ShowTransferScreen()
		{
			//cout << setw(37) << left << "\nTransfer Screen Will be here ...\n";
			clsTransferScreen::ShowTransferScreen();
		}

		static void _ShowTransferLogScreen()
		{
			//cout << setw(37) << left << "\nTransfer Log Screen Will be here ...\n";
			clsTransferLogScreen::ShowTransferLogScreen();
		}
		static void _ShowMainMenuScreen()
		{
			cout << setw(37) << left << "\nMain Menu Screen Will be here ...\n";
		}
		static void _GoBackToTransactionsMenu()
		{
			cout << setw(37) << left << "\nPress any key to go back to Transactions Menu...";
			system("pause>0");
			ShowTransactionsScreen();
		}

		static enTransactionsMenuOptions _PerfromTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption)
		{
			switch (TransactionsMenuOption)
			{
			case enDeposit:
			{
				system("cls");
				_ShowDepositScreen();
				_GoBackToTransactionsMenu();
				break;
			}
			case enWithdraw:
			{
				system("cls");
				_ShowWithdrawScreen();
				_GoBackToTransactionsMenu();
				break;
			}
			case enShowTotalBalance:
			{
				system("cls");
				_ShowTotalBalanceScreen();
				_GoBackToTransactionsMenu();
				break;
			}
			case enTransfer:
			{
				system("cls");
				_ShowTransferScreen();
				_GoBackToTransactionsMenu();
				break;
			}
			case enTransferLogScreen:
			{
				system("cls");
				_ShowTransferLogScreen();
				_GoBackToTransactionsMenu();
				break;
			}
			case enShowMainMenue:
			{
				//not implemented 
			}
			
			}
			return TransactionsMenuOption;
		}

public:
	static void ShowTransactionsScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}
		system("cls");
		clsScreen::_DrawScreenHeader("\t\tTransactions Screen", "Menu of the Transactions");
		
		cout << setw(37) << left << "\n\t\t\t\t==========================================================\n";
			cout << setw(37)<<left<<" \t\t\t\t              [1] Deposit.\n";
			cout << setw(37)<<left<<" \t\t\t\t              [2] Withdraw.\n";
			cout << setw(37)<<left<<" \t\t\t\t              [3] Show Total Balance.\n";
			cout << setw(37)<<left<<" \t\t\t\t              [4] Transfer\n";
			cout << setw(37)<<left<<" \t\t\t\t              [5] Show Transfer Log.\n";
			cout << setw(37)<<left<<" \t\t\t\t              [6] Show Main Menu.\n";
			cout << setw(37) << left << "\n\t\t\t\t==========================================================\n";
			_PerfromTransactionsMenuOption(enTransactionsMenuOptions(_ReadMainMenuOption()));
		
	}

};

