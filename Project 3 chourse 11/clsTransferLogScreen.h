#pragma once
#include <iostream>
#include"clsMainScreen.h"
#include"clsBankClient.h"
using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:
	static void _PrintTransferLogRecord(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << "|  " << setw(8) << left << "\n_________________________________________________________________________________________________________________\n";
		cout << "|  " << setw(23) << left << TransferLogRecord.DateTime;
		cout << "|  " << setw(8) << left << TransferLogRecord.AccountNumberFrom;
		cout << "|  " << setw(8) << left << TransferLogRecord.AccountNumberTo;
		cout << "|  " << setw(8) << left << TransferLogRecord.Amount;
		cout << "|  " << setw(12) << left << TransferLogRecord.SourceBalanceAfterTransfer;
		cout << "|  " << setw(12) << left << TransferLogRecord.DestinationBalanceAfterTransfer;
		cout << "|  " << setw(15) << left << TransferLogRecord.UserName;
		cout << "|  " << endl;
	}

public:
	static void ShowTransferLogScreen()
	{
		
		vector<clsBankClient::stTransferLogRecord>vTransferLogRecord = clsBankClient::GetTransferLogList();
		string Title = "\t Transfer Log List Screen ";
		string SubTitle = "\n\t\t\t\t\t\t (" + to_string(vTransferLogRecord.size()) + ") Record(s)\n";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "\n_________________________________________________________________________________________________________________\n";
		cout << "|  " << setw(23) << left << "Date/Time";
		cout << "|  " << setw(8) << left << "S.Acct";
		cout << "|  " << setw(8) << left << "D.Acct";
		cout << "|  " << setw(8) << left << "Amount";
		cout << "|  " << setw(12) << left << "S.Balance";
		cout << "|  " << setw(12) << left << "D.Balance";
		cout << "|  " << setw(8) << left << "User Name";
		cout << setw(8) << left << "\n_________________________________________________________________________________________________________________\n";
		if (vTransferLogRecord.size() > 0)
		{
			for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
			{
				_PrintTransferLogRecord(Record);
			}
			cout << setw(8) << left << "\n_________________________________________________________________________________________________________________\n";
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\tNo Transfer Log Record In the System !\n";
		}
	}
};

