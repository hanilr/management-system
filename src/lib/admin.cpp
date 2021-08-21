// ADMIN SECTION (ADMIN)

#include <iostream>

#include "file.hpp"
#include "admin.hpp"
using namespace std;

int create_account(string user_name, string user_pass, string user_pass_again)
{
    string full_path = "data/" + user_name + "/" + user_pass + ".txt";
    string log_path = "data/" + user_name + "/" + "log.txt";

    if(user_pass.compare(user_pass_again) == 0)
    {
        string command = "cd data & mkdir " + user_name;
        system(command.c_str());

        wfile(full_path, "0");
        wfile(log_path, "account has been created");
    }

    return 0;
} // CHECK ISSUES WITH "int var = create_account()"

int delete_account(string user_name, string user_name_again)
{
    string full_path = "data/" + user_name;

    if(user_name.compare(user_name_again) == 0)
    {
        #ifdef _WIN32
            string full_command = "cd data & rmdir /s /q " + user_name;
            system(full_command.c_str());
        #elif __unix__
            string full_command = "rm -rf " + full_path;
            system(full_command.c_str());
        #endif
    }

    return 0;
} // CHECK ISSUES WITH "int var = delete_account()"

int freeze_check(string user_name)
{
    string full_path = "data/" + user_name + "/log.txt";
    string freeze_msg = "account has been frozen";

    if(freeze_msg.compare(rfile(full_path)) == 0) { return 1; }

    return 0;
} // CHECK ISSUES WITH "int var = freeze_check()"

int ban_check(string user_name)
{
    string full_path = "data/" + user_name + "/log.txt";
    string ban_msg = "account has been banned";

    if(ban_msg.compare(rfile(full_path)) == 0) { return 1; }
    
    return 0;
} // CHECK ISSUES WITH "int var = ban_check()"

int ban_account(string user_name, string user_name_again)
{
    if(ban_check(user_name) == 1) { return 1; }

    string full_path = "data/" + user_name + "/log.txt";

    if(user_name.compare(user_name_again) == 0)
    {
        dfile(full_path);
        wlog(user_name, "account has been banned");
    }

    return 0;
} // CHECK ISSUES WITH "int var = ban_account()"

int unban_account(string user_name, string user_name_again)
{
    string full_path = "data/" + user_name + "/log.txt";

    if(user_name.compare(user_name_again) == 0)
    {
        dfile(full_path);
        wlog(user_name, "account has been unbanned");
    }

    return 0;
} // CHECK ISSUES WITH "int var = unban_account()"

int change_pass(string user_name, string user_pass, string new_pass)
{
    string old_path = "data/" + user_name + "/" + user_pass + ".txt";
    string new_path = "data/" + user_name + "/" + new_pass + ".txt";

    string temp_str = rfile(old_path);
    dfile(old_path);
    wfile(new_path, temp_str);

    return 0;
} // CHECK ISSUES WITH "int var = change_pass()"
