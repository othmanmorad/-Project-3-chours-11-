#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 ,AddNewMode};
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
	bool _MarkForDeleted = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }




    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string ClientRecrd;
        ClientRecrd += Client.FirstName + Seperator;
        ClientRecrd += Client.LastName + Seperator;
        ClientRecrd += Client.Email + Seperator;
        ClientRecrd += Client.Phone + Seperator;
        ClientRecrd += Client.AccountNumber() + Seperator;
        ClientRecrd += Client.PinCode + Seperator;
        ClientRecrd += to_string(Client.AccountBalance);
        return ClientRecrd;
    }

    static vector <clsBankClient> _LoadClientsDataFromFile(string FileName, string Seperator = "#//#")
    {
        vector<clsBankClient>vClients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode    
        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line, Seperator);
                vClients.push_back(Client);
            }
        }
        MyFile.close();
        return vClients;
    }






    static void _SaveClientsDataToFile(vector<clsBankClient>vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//write Mode
        if (MyFile.is_open())
        {
            for (clsBankClient Client : vClients)
            {
                if (Client._MarkForDeleted==false) // if this client marked for delete we will not write it to file.
                {
                    

                    string stClientRecord = _ConvertClientObjectToLine(Client);
                    MyFile << stClientRecord << endl;
                }
            }
            MyFile.close();
        }

    }

    void _Update()
    {
        vector<clsBankClient>_vClients;
        _vClients = _LoadClientsDataFromFile("Clients.txt");

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile(_vClients);
    }




    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }




	void _AddNewClient()
	{
		string stClientRecord = _ConvertClientObjectToLine(*this);
		_AddDataLineToFile(stClientRecord);
	}



    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }






public:


    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

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
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;




    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }

    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
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
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
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

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }



    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 ,svFaildAccountNumberExsist=2};

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {

            return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            if (IsClientExist(AccountNumber()))
            {
                return enSaveResults::svFaildAccountNumberExsist;
            }
            else
            {
				_AddNewClient();
                return enSaveResults::svSucceeded;
            }
            break;

        }

        }

    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)

    {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }


    bool Delete()
    {
        vector<clsBankClient>vClients;

		vClients = _LoadClientsDataFromFile("Clients.txt");     

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkForDeleted = true;   
				break;
			}
		}
		_SaveClientsDataToFile(vClients);

		*this = _GetEmptyClientObject(); // make this object empty after delete it from file.
        return true;
    }



	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile("Clients.txt");
	}


    static double GetTotalBalances()
    {
		vector<clsBankClient>vClients = GetClientsList();

		double TotalBalances = 0;
        for (clsBankClient Client : vClients)
        {
			TotalBalances += Client.AccountBalance;
        }

		return TotalBalances;   
    }
	
};
