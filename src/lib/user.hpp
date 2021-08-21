// USER FUNCTIONS LINKER (USER LINKER)

#ifndef _USER_HPP
#define _USER_HPP

#include <iostream>
using namespace std;

string fetch_value(string user_name, string user_pass);

int change_value(string user_name, string user_pass, string value);

int freeze_account(string user_name);

int unfreeze_account(string user_name);

#endif // FUNCTION NAMES ARE VERY CLEAR SO I DIDN'T WRITE ANY COMMENT IN HERE
