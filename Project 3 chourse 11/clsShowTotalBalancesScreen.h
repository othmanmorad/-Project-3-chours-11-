#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"	
#include"clsBankClient.h"	
#include"clsUtil.h"

using namespace std;

class clsShowTotalBalancesScreen : protected clsScreen
{
private:
	static void PrintClientRecordBalanceLine(clsBankClient Client)
	{

		cout << "|  " << setw(15) << left << Client.AccountNumber();
		cout << "|  " << setw(20) << left << Client.FullName();
		cout << "|  " << setw(12) << left << Client.AccountBalance;

	}

public:
	static void ShowClientsList()
	{
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();

		string Title = "\t  Balance List Screen";
		string SubTitle = "\n\t\t\t\t\t\t (" + to_string(vClients.size()) + ") Client(s)\n";

		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "\n________________________________________________________________________________________________________________________\n";

		cout << "|  " << setw(15) << left << "AccountNumber";
		cout << "|  " << setw(20) << left << "FullName";
		cout << "|  " << setw(12) << left << "AccountBalance";

		double TotalBalances = clsBankClient::GetTotalBalances();
		if (vClients.size() > 0)
		{
			cout << setw(8) << left << "\n________________________________________________________________________________________________________________________\n";
			for (clsBankClient Client : vClients)
			{
				PrintClientRecordBalanceLine(Client);
				cout << setw(8) << left << "\n________________________________________________________________________________________________________________________\n";
			}
			
			cout << setw(8) << left << "\n________________________________________________________________________________________________________________________\n";
			cout << "|  " << setw(15) << left << "\nTotal Balances\n"<<TotalBalances<<endl;
			cout << setw(8) << left << clsUtil::NumberToText(TotalBalances);
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\tNo Clients Available In the System !\n";
		}

	}



};
