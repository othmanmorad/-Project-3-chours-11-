#include <iostream>
#include<iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"  
#include "clsLoginScreen.h"
int main()
{
	while (true)
	{

		if(!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}

	}
	
    
    return 0;
}
