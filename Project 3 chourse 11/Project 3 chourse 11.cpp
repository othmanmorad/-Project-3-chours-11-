
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include"clsBankClient.h"

using namespace std;


int main()
{
    clsBankClient Client = clsBankClient::Find("A101");
    if (!Client.IsEmpty())
    {
        cout << "\nClient Found :)\n";
    }
    else
    {
        cout<<"\nClient Was Not Found :)\n";
    }
    Client.Print();



    clsBankClient Client2 = clsBankClient::Find("A102","12344");
    if (!Client2.IsEmpty())
    {
        cout << "\nClient Found :)\n";
    }
    else
    {
        cout << "\nClient Was Not Found :)\n";
    }
    Client2.Print();



    system("pause>0");
    return 0;
}

