#pragma once

#include <iostream>
#include <string>

using namespace std;


class clsPerson
{

private :

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	clsPerson(string FirstNmae, string LastName, string Email, string Phone)
	{
		_FirstName = FirstNmae;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;


	}


	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	_declspec(property(get = GetFirstName, put =SetFirstName))string FirstName;





	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}

	_declspec(property(get = GetLastName, put = SetLastName))string LastName;





	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	_declspec(property(get = GetEmail, put = SetEmail))string Email;





	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	string GetPhone()
	{
		return _Phone;
	}

	_declspec(property(get = GetPhone, put = SetPhone))string Phone;


	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void Print()
	{
		cout << "\nInfo" << endl;
		cout << "\n------------------" << endl;
		cout << "\nFirst Nmae : "<<_FirstName << endl;
		cout << "\nLast Nmae : " << _LastName << endl;
		cout << "\nFull Nmae : " << FullName() << endl;
		cout << "\nEmail : " << _Email << endl;
		cout << "\nPhone : " << _Phone << endl;
		cout << "\n------------------" << endl;
	}

};

