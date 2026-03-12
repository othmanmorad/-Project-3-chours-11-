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
