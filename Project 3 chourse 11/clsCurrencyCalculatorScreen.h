#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
using namespace std;
class clsCurrencyCalculatorScreen : protected clsScreen
{
private :

	static float _ReadRate()
	{
		float Rate = 0;
		cout << "\nPlease Enter Currency Rate ? : ";
		Rate = clsInputValidate::ReadFloatNumber();
		return Rate;
	}
	static void _PrintCurrency(clsCurrency Currency , string Title="Currency card")
	{
		cout << Title << "\n";	
		cout << "----------------------------------------------\n";
		cout << "\nCountry      : " << Currency.Country();
		cout << "\nCurrency Code: " << Currency.CurrencyCode();
		cout << "\nCurrency Name: " << Currency.CurrencyName();
		cout << "\nRate (1$)    : " << Currency.Rate() << endl;
		cout << "----------------------------------------------\n";
	}
	static void _PrintCalculateResult(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{
		_PrintCurrency(CurrencyFrom, "\n\t\tCurrency From");
		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << " USD\n";

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConvert From Usd to:\n";
		_PrintCurrency(CurrencyTo, "\t\tCurrency To");

		float AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount,CurrencyTo);	
		cout << Amount << " " << CurrencyFrom.CurrencyCode() <<
			" = " << AmountInCurrencyTo<< " "<<CurrencyTo.CurrencyCode() << "\n";

	}
	static clsCurrency _GetCurrency(string Message)
	{
		cout << Message;
		string CurrencyCode;
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nNo Currency Available In the System With This Code !\n";
			cout << "\nPlease Currency code ? : ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency= clsCurrency::FindByCurrencyCode(CurrencyCode);
		return Currency;
	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Continue='y';
		
		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\t  Currency Calculator Screen");
			clsCurrency CurrencyFrom = _GetCurrency("\nPlease entr currency1 code \n");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease entr currency2 code \n");
			float Amount = _ReadRate();

			_PrintCalculateResult(CurrencyFrom, CurrencyTo, Amount);

			cout << "\nDo you want to perform Another Currency Exchange ? [y] [n] ? : \n";
			cin >> Continue;

		}

	}
	
	

	
};

