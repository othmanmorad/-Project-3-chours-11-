#pragma once
#include <string>
#include <vector>
#include "clsString.h"
#include <fstream>
using namespace std;
class clsCurrency
{
private:
	enum enMode { EmptyMode = 1, UpdateMode = 2 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	
	static clsCurrency _ConvertLineCurrencyToObject(string Line, string Sperator="#//#")
	{
		vector<string> vCurrencyData = clsString::Split(Line, Sperator);
		return clsCurrency(UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));

	}
	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Sperator = "#//#")
	{

		string stCurrencyRecord;
		stCurrencyRecord += Currency.Country() + Sperator;
		stCurrencyRecord += Currency.CurrencyCode() + Sperator;
		stCurrencyRecord += Currency.CurrencyName() + Sperator;
		stCurrencyRecord += to_string(Currency.Rate());
		return stCurrencyRecord;

	}


	static vector <clsCurrency> _LoadCurrencysDataFromFile()
	{
		vector<clsCurrency>vCurrencys;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode    
		if (MyFile.is_open())
		{

			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Client = _ConvertLineCurrencyToObject(Line);
				vCurrencys.push_back(Client);
			}
		}
		MyFile.close();
		return vCurrencys;
	}






	static void _SaveCurrencysDataToFile(vector<clsCurrency>vCurrencys)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//write Mode
		if (MyFile.is_open())
		{
			for (clsCurrency Currency : vCurrencys)
			{
				

					string stClientRecord = _ConvertCurrencyObjectToLine(Currency);
					MyFile << stClientRecord << endl;
				
			}
			MyFile.close();
		}

	}



	


	void _Update()
	{
		vector<clsCurrency>vCurrencys = _LoadCurrencysDataFromFile();
		for (clsCurrency& Currency : vCurrencys)
		{
			if (Currency.CurrencyCode() == CurrencyCode())
			{
				Currency = *this;
				break;
			}
		}
		_SaveCurrencysDataToFile(vCurrencys);
	}





	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(EmptyMode, "", "", "", 0);
	}	



public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	bool IsEmpty()
	{
		return (_Mode == EmptyMode);
	}	
	string Country() { return _Country; }
	string CurrencyCode() { return _CurrencyCode; }
	string CurrencyName() { return _CurrencyName; }
	void UpdateRate(float NewRate) 
	{
		_Rate = NewRate; 
		_Update();	
	}
	float Rate() { return _Rate; }

	static clsCurrency FindByCurrencyCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineCurrencyToObject(Line);
				if (clsString ::UpperAllString(Currency.CurrencyCode() )== CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
		
	}




	static clsCurrency FindByCurrencyCountry(string CurrencyCountry)
	{
		CurrencyCountry = clsString::UpperAllString(CurrencyCountry);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineCurrencyToObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == CurrencyCountry)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();

	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = FindByCurrencyCode(CurrencyCode);
		return( !C1.IsEmpty());
	}

	static vector <clsCurrency>GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	}

};

