#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

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

int main()

{
    UpdateClient();
    system("pause>0");
    return 0;
}
