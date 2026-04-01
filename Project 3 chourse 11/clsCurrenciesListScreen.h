#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include"clsCurrency.h"
#include<vector>
using namespace std;	

class clsCurrenciesListScreen : protected clsScreen
{

private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout<<"|  " << setw(28) << left << Currency.Country();
		cout<<"|  " << setw(13) << left << Currency.CurrencyCode();
		cout<<"|  " << setw(28) << left << Currency.CurrencyName();
		cout<<"|  " << setw(17) << left << Currency.Rate() << endl;
	}

public:
	static void ShowCurrenciesListScreen()
	{
		vector<clsCurrency>vCurrencys = clsCurrency::GetCurrenciesList();
		
		string Title = "\t  Currency List Screen";
		string SubTitle = "\n\t\t\t\t\t\t(" + to_string(vCurrencys.size()) + ") Currencie(s)\n";

		_DrawScreenHeader(Title, SubTitle);
		cout<<"|  "<< setw(8) << left << "\n________________________________________________________________________________________\n";
		cout<<"|  "<< setw(28) << left << "Country";
		cout<<"|  "<< setw(8) << left << "Currency Code";
		cout<<"|  "<< setw(28) << left << "Currency Name";
		cout<<"|  "<< setw(28) << left << "Rate" << endl;
		cout<<"|  "<< setw(8) << left << "\n_________________________________________________________________________________________\n";
		
		if (vCurrencys.size() > 0)
		{
			for (clsCurrency Currency : vCurrencys)
			{
				_PrintCurrencyRecordLine(Currency);
				cout << setw(8) << left << "\n________________________________________________________________________________________\n";
			}
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\tNo Currencies Available In the System !\n";
		}
	}
};

