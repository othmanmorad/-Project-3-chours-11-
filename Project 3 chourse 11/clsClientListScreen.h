
#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"	
#include"clsBankClient.h"	

using namespace std;

class clsClientListScreen : protected clsScreen
{
private:
	static void PrintClientRecordLine(clsBankClient Client)
	{

		cout << "|  " << setw(15) << left << Client.AccountNumber();
		cout << "|  " << setw(20) << left << Client.FullName();
		cout << "|  " << setw(12) << left << Client.Phone;
		cout << "|  " << setw(20) << left << Client.Email;
		cout << "|  " << setw(10) << left << Client.PinCode;
		cout << "|  " << setw(12) << left << Client.AccountBalance;

	}

public:
	static void ShowClientsList()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;
		}
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();

		string Title = "\t  Client List Screen";
		string SubTitle = "\n\t\t\t\t\t\tClients List (" +to_string( vClients.size() )+ ") Client(s)\n";

		_DrawScreenHeader(Title, SubTitle);	
		cout <<setw(8)<<left<< "\n________________________________________________________________________________________________________________________\n";

		cout << "|  " << setw(15) << left << "AccountNumber";
		cout << "|  " << setw(20) << left << "FullName";
		cout << "|  " << setw(12) << left << "Phone";
		cout << "|  " << setw(20) << left << "Email";
		cout << "|  " << setw(10) << left << "PinCode";
		cout << "|  " << setw(12) << left << "AccountBalance";

		if (vClients.size() > 0)
		{
			cout << setw(8) << left << "\n________________________________________________________________________________________________________________________\n";
			for (clsBankClient Client : vClients)
			{
				PrintClientRecordLine(Client);
				cout << setw(8) << left << "\n________________________________________________________________________________________________________________________\n";
			}
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\tNo Clients Available In the System !\n";
		}

	}



};

