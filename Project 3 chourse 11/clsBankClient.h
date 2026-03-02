#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include"clsString.h"
#include"clsPerson.h"
using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum enMode{EmptyMode=0 , UpDateMode=1};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLineToClientObject(string Line ,string Sperator="#//#")
	{
		vector <string>vClientDate;

		vClientDate = clsString::Split(Line, Sperator);

		return clsBankClient(enMode::UpDateMode, vClientDate[0], vClientDate[1], vClientDate[2],
			vClientDate[3], vClientDate[4], vClientDate[5], stod (vClientDate[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return  clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:
	clsBankClient(enMode Mode, string FirstNmae, string LastName, 
		string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance):
		clsPerson(FirstNmae, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}


	string AccountNumber()
	{
		return _AccountNumber;
	}



	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	_declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;





	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	_declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;



	void Print()
	{
		cout << "\nClient card" << endl;
		cout << "\n------------------" << endl;
		cout << "\nFirst Nmae : " << FirstName << endl;
		cout << "\nLast Nmae : " << LastName << endl;
		cout << "\nFull Nmae : " << FullNmae() << endl;
		cout << "\nEmail : " << Email << endl;
		cout << "\nPhone : " << Phone << endl;
		cout << "\nAccount Number : " << _AccountNumber << endl;
		cout << "\nPassword : " << _PinCode << endl;
		cout << "\nAccount Balance : " << _AccountBalance << endl;
		cout << "\n------------------" << endl;
	}


	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);//read only 

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber () == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}




	
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode==PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}


	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find( AccountNumber);

		return (!Client.IsEmpty());
	}


};




