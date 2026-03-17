#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsString.h"
#include "clsBankClient.h"
#include "clsUsersListScreen.h"

using namespace std;
class clsUser : public clsPerson
{

private:
	enum enMode { enEmptyMode = 0, enUpdateMode = 1, enAddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;	
	
	static clsUser _ConvertUserLineToUserObject(string UserLine, string Spreator ="#//#")
	{
		vector <string> vUserData;
		vUserData = clsString::Split(UserLine, Spreator);
		return clsUser(enMode::enUpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], vUserData[5] ,stoi (vUserData[6]));
		
	}
	static string _ConvertUserObjectToUserLine(clsUser User , string Spreator = "#//#")
	{
		string UserLine = "";
		UserLine += User.UserName + "#//#";
		UserLine += User.FirstName + "#//#";
		UserLine += User.LastName + "#//#";
		UserLine += User.Email + "#//#";
		UserLine += User.Phone + "#//#";
		UserLine += User.Password + "#//#";
		UserLine +=to_string(User.Permission);
		return UserLine;
	}
	static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;
		
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
			 clsUser User = _ConvertUserLineToUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;	
		
	}
	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsUser User : vUsers)
			{
				if (User._MarkedForDelete==false)
				{

					string UserLine = _ConvertUserObjectToUserLine(User);
					MyFile << UserLine << endl;

				}
			}
			MyFile.close();
		}

	}
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enEmptyMode, "", "", "", "", "", "", 0);
	}
	
	void _Update()
	{
		vector <clsUser> vUsers;
		vUsers = _LoadUsersDataFromFile();
		for (clsUser& User : vUsers)
		{
			if (User.UserName == UserName)
			{
				User = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}
	
	void _AddDataLineToFile(string UserLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << UserLine << endl;
			MyFile.close();
		}
	}
	void _AddNewUser()
	{
		_AddDataLineToFile(_ConvertUserObjectToUserLine(*this));
	}

public:
	
	clsUser(enMode Mode,string FirstName,string LastName,string Emaile,
		string Phone,string UserName ,string Password,int Permissions):
		clsPerson(FirstName, LastName, Emaile, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enEmptyMode);
	}


	 void SetUserName(string UserName) 
	 {
		 _UserName = UserName;

	 }
	 string GetUserName() 
	 {
		 return _UserName;
	 }
	 _declspec(property(get = GetUserName, put = SetUserName)) string UserName;


	 void SetPassword(string Password)
	 { 
		 _Password = Password;
	 }
	 string GetPassword()
	 {
		 return _Password;
	 }
	_declspec(property(get = GetPassword, put = SetPassword)) string Password;


	 void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	 int GetPermissions() 
	 { 
		 return _Permissions;
	 }
	_declspec(property(get = GetPermissions, put = SetPermissions)) int Permission;

	static clsUser Find(string UserName)
	{


		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertUserLineToUserObject(Line);
				if (User._UserName ==UserName)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName ,string Password)
	{


		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertUserLineToUserObject(Line);
				if (User._UserName == UserName && User.Password==Password)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserNameExsist = 2 };
	
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enEmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}
		case enUpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}
		case enAddNewMode:
		{
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserNameExsist;
			}
			else
			{
				_AddNewUser();
				return enSaveResults::svSucceeded;
			}
			break;
		}
		}

	}







	 static bool IsUserExist(string UserName)
	{
		clsUser User1 = clsUser::Find(UserName);
		return (!User1.IsEmpty());
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}
	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::enAddNewMode, "", "", "", "","UserName", "", 0);
	}
	bool  Delete(string UserName)
	{
		vector <clsUser> vUsers;
		vUsers = _LoadUsersDataFromFile();
		for (clsUser& User : vUsers)
		{
			if (User.UserName == UserName)
			{
				User._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);

	}


};

