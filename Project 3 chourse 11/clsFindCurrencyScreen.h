#pragma once
#include <iostream>
#include"clsScreen.h"	
#include"clsCurrency.h"
#include"clsInputValidate.h"
using namespace std;	
class clsFindCurrencyScreen : protected clsScreen
{
private :
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "----------------------------------------------\n";	
		cout << "\nCountry      : " << Currency.Country();
		cout << "\nCurrency Code: " << Currency.CurrencyCode();
		cout << "\nCurrency Name: " << Currency.CurrencyName();
		cout << "\nRate (1$)    : " << Currency.Rate() << endl;
		cout << "----------------------------------------------\n";
	}
	static void _ShowResult(clsCurrency Currency)
	{
		if (Currency.IsEmpty())
		{
			cout << "\n\t\t\t\t\t\t\t\tNo Currency Available In the System With This Data !\n";
		}
		else
		{
			_PrintCurrency(Currency);
		}
	}


public:
	static void ShowFindCurrencyScreen()
	{
		string Title = "\t  Find Currency Screen";
		_DrawScreenHeader(Title);
		cout << "\n\n\t\t\t\t\t\t   Find By:[1] Code or [2] Country ? : ";
		short Answer;
		cin >> Answer;
		while (Answer != 1 && Answer != 2)
		{
			cout << "\n\t\t\t\t\t\t   Wrong Choice, Choose Again ? : ";
			cin >> Answer;
		}
		if (Answer == 1)
		{
			string  CurrencyCode;
			cout << "\n\t\t\t\t\t\t   Currency Code ? : ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
			_ShowResult(Currency);
		}
		else
		{
			string  CurrencyCountry;
			cout << "\n\t\t\t\t\t\t   Currency Country ? : ";
			CurrencyCountry = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCurrencyCountry(CurrencyCountry);
			_ShowResult(Currency);
		}
		
	}	

};

