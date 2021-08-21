// USER SECTION (USER)

#include <iostream>

#include "file.hpp"
using namespace std;

string fetch_value(string user_name, string user_pass)
{
    string full_path = "data/" + user_name + "/" + user_pass + ".txt";
    string temp_value = rfile(full_path);

    return temp_value;
} // CHECK ISSUES WITH "int var = fetch_value()"

int change_value(string user_name, string user_pass, string value)
{
    string full_path = "data/" + user_name + "/" + user_pass + ".txt";

    dfile(full_path);
    wfile(full_path, value);

    return 0;
} // CHECK ISSUES WITH "int var = add_value()"

int freeze_account(string user_name)
{
    string full_path = "data/" + user_name + "/log.txt";

    wlog(full_path, "account has been frozen");

    return 0;
} // CHECK ISSUES WITH "int var = freeze_account()"

int unfreeze_account(string user_name)
{
    string full_path = "data/" + user_name + "/log.txt";

    wlog(full_path, "account has been unfreeze");

    return 0;
} // CHECK ISSUES WITH "int var = unfreeze_account()"
