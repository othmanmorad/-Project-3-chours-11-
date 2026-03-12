#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsDeleteClientScreen : protected clsScreen   
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



   static void ShowDeletClientScreen()
    {
		_DrawScreenHeader("\t\tDelete Client Screen", "Delete Client From the System");
        
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

        cout << "Are you sure you want to delete this account ? y/n : ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\nAccount Deleted Successfully.\n";
            }
            else
            {
                cout << "\nFailed to Delete Account.\n";
            }

        }



    }


};

