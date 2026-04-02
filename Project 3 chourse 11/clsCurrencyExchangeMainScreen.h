#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"	
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"
using namespace std;	
class clsCurrencyExchangeMainScreen : protected clsScreen
{
private :
	enum enCurrencyExchangeMainMenuOptions{enListCurrencies=1 , enFindCurrency=2,enUpdateCurrencyRate=3
		,enCurrencyCalculator=4,enMainMenue=5};



	static short _ReadMainMenuOption()
	{
		cout << "\t\t\t\t\tChoose what do you want to do? [1-5] : ";


		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "\n\n\t\t\t\t\tChoose what do you want to do? [1-5]");

		return Choice;
	}

	static void _GoBackToCurrencyExchangeMainMenu()
	{
		cout << setw(37) << left << "\nPress any key to go back to Curency exchange Main Menu...";
		system("pause>0");
		ShowCurrencyExchangeMainScreen();
	}

	static void ShowListCurrenciesScreen()
	{
		//cout << setw(37) << left << "\nList Currencies Screen Will be here ...\n";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();	
	}

	static void ShowFindCurrencyScreen()
	{
		//cout << setw(37) << left << "\nFind Currency Screen Will be here ...\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();	
	}

	static void ShowUpdateRateScreen()
	{
		//cout << setw(37) << left << "\nUpdate Rate Screen Will be here ...\n";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyRateScreen();	
	}

	static void ShowCurrencyCalculatorScreen()
	{
		//cout << setw(37) << left << "\nCurrency Calculator Screen Will be here ...\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerfromCurrencyMainMenuOption(enCurrencyExchangeMainMenuOptions CurrenciesMainMenuOption)
	{
		switch (CurrenciesMainMenuOption)
		{
		case enListCurrencies:
		{
			system("cls");
			ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMainMenu();
			break;
		}
		case enFindCurrency:
		{
			system("cls");
			ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMainMenu();
			break;
		}
		case enUpdateCurrencyRate:
		{
			system("cls");
			ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMainMenu();
			break;
		}
		case enCurrencyCalculator:
		{
			system("cls");
			ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMainMenu();
			break;
		}

		case enMainMenue:
		{
			//do nothing here the main screen will handle 
		}

		}
		

	}


public:

	static void ShowCurrencyExchangeMainScreen()
	{
		system("cls");
	   _DrawScreenHeader("\tCurrency Exchange Main Screen", "\n\t\t\t\t\tWelcome To Currency Exchange Main Screen");
	   cout << setw(37) << left << "\n\t\t\t\t==========================================================\n";
	   cout << setw(37) << left << "\n\t\t\t\t\t Currency Exchange Menue.\n";
	   cout << setw(37) << left << "\n\t\t\t\t==========================================================\n";
		cout << setw(37) << left << "\n\n\t\t\t\t\t[1]. List Currencies.";
		cout << setw(37) << left << "\n\n\t\t\t\t\t[2]. Find Currency.";
		cout << setw(37) << left << "\n\n\t\t\t\t\t[3]. Update Rate.";
		cout << setw(37) << left << "\n\n\t\t\t\t\t[4]. Currency Calculator.";
		cout << setw(37) << left << "\n\n\t\t\t\t\t[5]. Main Menu.\n";
		cout << setw(37) << left << "\n\t\t\t\t==========================================================\n";
		_PerfromCurrencyMainMenuOption((enCurrencyExchangeMainMenuOptions)_ReadMainMenuOption());
	}






};



