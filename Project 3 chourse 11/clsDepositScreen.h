#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"	
class clsDepositScreen : protected clsScreen
{
private:

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "Enter Account Number : ";
		cin >> AccountNumber;
		return AccountNumber;
	}	

	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:

	static void ShowDepositScreen()
	{

		_DrawScreenHeader("\t\tDeposit Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client with "<< AccountNumber<<" was not found, enter anoter one.";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);


		cout << "\nEnter Amount to Deposit : ";
		double Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure you want to make a deposit for this client? [y/n] : ";	
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			
			Client.Deposit(Amount);
			Client.Save();
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance : " << Client.AccountBalance << "\n";
		}
		else
		{
			cout << "\nDeposit Cancelled.\n";

		}
	}












};

