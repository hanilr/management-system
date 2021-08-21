// ADMIN FUNCTIONS LINKER (ADMIN LINKER)

#ifndef _ADMIN_HPP
#define _ADMIN_HPP

#include <iostream>
using namespace std;

int create_account(string user_name, string user_pass, string user_pass_again);

int delete_account(string user_name, string user_name_again);

int freeze_check(string user_name);

int ban_check(string user_name);

int ban_account(string user_name, string user_name_again);

int unban_account(string user_name, string user_name_again);

int change_pass(string user_name, string user_pass, string new_pass);

#endif // FUNCTION NAMES ARE VERY CLEAR SO I DIDN'T WRITE ANY COMMENT IN HERE
