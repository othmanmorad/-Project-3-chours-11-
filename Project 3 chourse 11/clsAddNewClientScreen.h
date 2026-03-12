#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"	
#include"clsBankClient.h"	
#include"clsInputValidate.h"    
class clsAddNewClientScreen : protected clsScreen
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



   static void Print(clsBankClient Client)
   {
       cout << "\nClient Card:";
       cout << "\n___________________";
       cout << "\nFirstName   : " <<Client.FirstName;
       cout << "\nLastName    : " <<Client.LastName;
       cout << "\nFull Name   : " <<Client.FullName();
       cout << "\nEmail       : " <<Client.Email;
       cout << "\nPhone       : " <<Client.Phone;
       cout << "\nAcc. Number : " <<Client.AccountNumber();
       cout << "\nPassword    : " <<Client.PinCode;
       cout << "\nBalance     : " <<Client.AccountBalance;
       cout << "\n___________________\n";

   }




   
public:

  static  void ShowAddNewClientScreen()
    {

      _DrawScreenHeader("\t\tAdd New Client Screen");

        string AccountNumber = "";


        cout << "\nEnter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number was already used , enter anoter one.";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);




        cout << "\nAdd Client Info : \n";
        ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Added Successfully.\n";
            Print(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\n Error Account was not saved because Account number is used !\n";
            break;
        }
        case clsBankClient::svFaildAccountNumberExsist:
        {
            cout << "\nFailed to Add Client, Error Account was not saved because it's used\n";
            break;
        }
        }
    }





};

