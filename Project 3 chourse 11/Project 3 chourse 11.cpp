#include <iostream>
#include<iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"  


void ReadClientInfo(clsBankClient& Client)
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

void UpdateClient()
{
    string AccountNumber = "";

    cout << "Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "Account Number was not found , enter anoter one.";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);

    Client.Print();


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


void AddClient()
{
    string AccountNumber = "";

    cout << "Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "Account Number was not found , enter anoter one.";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

  


    cout << "\nAdd Client Info : \n";
    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult = NewClient.Save();


    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Added Successfully.\n";
        NewClient.Print();
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





void DeletClient()
{
    string AccountNumber = "";

    cout << "Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "Account Number was not found , enter anoter one.";
        AccountNumber = clsInputValidate::ReadString();
    }


    clsBankClient Client = clsBankClient::Find(AccountNumber);

    Client.Print();

	cout << "Are you sure you want to delete this account ? y/n : ";

	char Answer = 'n';
	cin >> Answer;

    if (Answer=='y' || Answer=='Y')
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






void PrintClientRecordLine(clsBankClient Client)
{
    
    cout << "|  " << setw(15) << left << Client.AccountNumber();
    cout << "|  " << setw(20) << left << Client.FullName();
    cout << "|  " << setw(12) << left << Client.Phone;
    cout << "|  " << setw(20) << left << Client.Email;
    cout << "|  " << setw(10) << left << Client.PinCode;
    cout << "|  " << setw(12) << left << Client.AccountBalance;

}






void ShowClientsList()
{
    vector<clsBankClient>vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\t\t\t\tClients List (" << vClients.size() << ") Client(s)\n";

	cout << "________________________________________________________________________________________________________________________\n";

    cout << "|  " << setw(15) << left << "AccountNumber";
    cout << "|  " << setw(20) << left << "FullName";
    cout << "|  " << setw(12) << left << "Phone";
    cout << "|  " << setw(20) << left << "Email";
    cout << "|  " << setw(10) << left << "PinCode";
    cout << "|  " << setw(12) << left << "AccountBalance";

	if (vClients.size() > 0)
	{
		cout << "\n________________________________________________________________________________________________________________________\n";
		for (clsBankClient Client : vClients)
		{
			PrintClientRecordLine(Client);
			cout << "\n________________________________________________________________________________________________________________________\n";
		}
	}
	else
	{
		cout << "\n\t\t\t\t\t\t\t\tNo Clients Available In the System !\n";
	}

}










void PrintClientRecordBalanceLine(clsBankClient Client)
{

    cout << "|  " << setw(15) << left << Client.AccountNumber();
    cout << "|  " << setw(20) << left << Client.FullName();
    cout << "|  " << setw(12) << left << Client.AccountBalance;

}

void ShowTotalBalnces()
{
    vector<clsBankClient>vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\t\t\t\tClients List (" << vClients.size() << ") Client(s)\n";

    cout << "________________________________________________________________________________________________________________________\n";

    cout << "|  " << setw(15) << left << "AccountNumber";
    cout << "|  " << setw(20) << left << "FullName";
    cout << "|  " << setw(12) << left << "AccountBalance";

    double TotalBalances = clsBankClient::GetTotalBalances();
    if (vClients.size() > 0)
    {
        cout << "\n________________________________________________________________________________________________________________________\n";
        for (clsBankClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout << "\n________________________________________________________________________________________________________________________\n";
        }

		cout << "\n\t\t\t\t\t\t\t\tTotal Balances = " << TotalBalances<< endl;
		cout << clsUtil::Tabs(10) << "Total Balances in Text : " << clsUtil::NumberToText(TotalBalances) << endl;

    }
    else
    {
        cout << "\n\t\t\t\t\t\t\t\tNo Clients Available In the System !\n";
    }




}




int main()

{
	clsMainScreen::ShowMainMenu();
    
    return 0;
}
