#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
private:
   static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\n Enter First Name : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\n Enter Last Name : ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\n Enter Full Name : ";
        Client.FullName() = clsInputValidate::ReadString();

        cout << "\n Enter Email : ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\n Enter Phone : ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\n Enter Pin Code : ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\n Enter Account Balance : ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();

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

   static void ShowUpdateClientScreen()
    {
	   if (!_CheckAccessRights(clsUser::enPermissions::pUpdateClients))
	   {
		   return;
	   }    
	   _DrawScreenHeader("\t\tUpdate Client Screen", "Update Client Info in the System");   
        string AccountNumber = "";

        cout << "Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number was not found , enter anoter one.";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _Print(Client);


        cout << "\nUpdate Client Info : \n";
        ReadClientInfo(Client);

        clsBankClient::enSaveResults SaveResult = Client.Save();


        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nClient Updated Successfully.\n";
            Client.Print();
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nFailed to Update Client, Error Account was not saved because it's Empty\n";
            break;
        }
        }
    }




};

