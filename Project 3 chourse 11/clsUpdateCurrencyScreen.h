#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsCurrency.h"	
#include"clsInputValidate.h"

using namespace std;	
class clsUpdateCurrencyScreen : protected clsScreen
{

private:

	static float _ReadNewRate()
	{
		cout << "\nPlease  New Rate For This Currency ? : ";
		float NewRate = 0;
			NewRate =clsInputValidate::ReadFloatNumber();
		return NewRate;
	}


	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "----------------------------------------------\n";
		cout << "\nCountry      : " << Currency.Country();
		cout << "\nCurrency Code: " << Currency.CurrencyCode();
		cout << "\nCurrency Name: " << Currency.CurrencyName();
		cout << "\nRate (1$)    : " << Currency.Rate() << endl;
		cout << "----------------------------------------------\n";
	}

	




public:
	static void ShowUpdateCurrencyRateScreen()
	{
		string Title = "\t  Update Currency Screen";
		_DrawScreenHeader(Title);
		string  CurrencyCode;
		cout << "\n\nPlease Enter Currency Code ? : ";
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nNo Currency Available In the System With This Code !\n";
			cout << "\nPlease Enter Currency Code ? : ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
		_PrintCurrency(Currency);
		cout << "\nAre you shur to update this rate Currency ? [y] [n] ? : \n";
		char Answer;
		cin >> Answer;
		
		if (Answer == 'y' || Answer == 'Y')
		{
			
			Currency.UpdateRate(_ReadNewRate());
			cout << "\nCurrency Updated Successfully !\n";
			_PrintCurrency(Currency);
		}
		
	}









};

