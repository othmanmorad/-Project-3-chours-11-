#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsFindClientScreen : protected clsScreen
{

private:

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
	static void ShowUpdateClientScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		_DrawScreenHeader("\t\tFind Client Screen");

		string AccountNumber = "";
		cout << "Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number was not found , enter anoter one.";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);


		if (!Client.IsEmpty())
		{
			cout << "\nClient was  found ";
			
		}
		else
		{
			cout << "\nClient was not found ";
		}
		_Print(Client);

	}

};

