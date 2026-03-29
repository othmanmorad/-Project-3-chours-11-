#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"Global.h"	
#include"Global.h"	
using namespace std;
class clsTransferScreen : protected clsScreen
{
private:

	static string _ReadAccountNumber(string Message)
	{
		string AccountNumber = "";
		cout << Message;
		cin >> AccountNumber;
		return AccountNumber;
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}
	static float _ReadAmount(clsBankClient SourceClient )
	{
		float Amount = 0;
		cout << "\nEnter Transfer Amount : ";
		Amount = clsInputValidate::ReadFloatNumber();	
		while (Amount <= 0 || Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the current balance, please enter another amount : ";
			Amount = clsInputValidate::ReadFloatNumber();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{

		_DrawScreenHeader("\t\tTransfer Screen\n\n");
		string AccountNumberFrom = _ReadAccountNumber("\n\nPlease Enter Account Number to Transfer From : ");
		while (!clsBankClient::IsClientExist(AccountNumberFrom))
		{
			cout << "Client with " << AccountNumberFrom << " was not found, enter anoter one.";
			AccountNumberFrom = _ReadAccountNumber("Please Enter Account Number to Transfer From : ");
		}
		clsBankClient SourceClient = clsBankClient::Find(AccountNumberFrom);
		_PrintClient(SourceClient);


		string AccountNumberTo = _ReadAccountNumber("Please Enter Account Number to Transfer to : ");
		while (!clsBankClient::IsClientExist(AccountNumberTo))
		{
			cout << "Client with " << AccountNumberTo << " was not found, enter anoter one.";
			AccountNumberTo = _ReadAccountNumber("Please Enter Account Number to Transfer to : ");
		}
		clsBankClient DestinationClient = clsBankClient::Find(AccountNumberTo);
		_PrintClient(DestinationClient);


		
		float Amount = _ReadAmount(SourceClient);

		cout << "\nAre you sure you want to perform this operation? [y/n] : ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount,DestinationClient ,CurrentUser.UserName))
			{

				cout << "\nTransfer done Succeefully.\n";
			}
			else
			{
				cout << "\nTransfer Failed.\n";
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
		
	}
};

