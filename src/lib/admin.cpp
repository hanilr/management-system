// ADMIN SECTION (ADMIN)

#include <iostream>

#include "file.hpp"
#include "admin.hpp"

void create_account(std::string user_name, std::string user_pass, std::string user_pass_again)
{
    std::string full_path = "data/" + user_name + "/" + user_pass + ".txt";
    std::string log_path = "data/" + user_name + "/" + "log.txt";

    if(user_pass.compare(user_pass_again) == 0)
    {
        std::string command = "cd data & mkdir " + user_name;
        system(command.c_str());

        wfile(full_path, "0");
        wfile(log_path, "account has been created");
    }
} 

void delete_account(std::string user_name, std::string user_name_again)
{
    std::string full_path = "data/" + user_name;

    if(user_name.compare(user_name_again) == 0)
    {
        #ifdef _WIN32
            std::string full_command = "cd data & rmdir /s /q " + user_name;
            system(full_command.c_str());
        #elif __unix__
            std::string full_command = "rm -rf " + full_path;
            system(full_command.c_str());
        #endif
    }
} // CHECK ISSUES WITH "int var = delete_account()"

int freeze_check(std::string user_name)
{
    std::string full_path = "data/" + user_name + "/log.txt";
    std::string freeze_msg = "account has been frozen";

    if(freeze_msg.compare(rfile(full_path)) == 0) { return 1; }

    return 0;
} // CHECK ISSUES WITH "int var = freeze_check()"

int ban_check(std::string user_name)
{
    std::string full_path = "data/" + user_name + "/log.txt";
    std::string ban_msg = "account has been banned";

    if(ban_msg.compare(rfile(full_path)) == 0) { return 1; }
    
    return 0;
} // CHECK ISSUES WITH "int var = ban_check()"

void ban_account(std::string user_name, std::string user_name_again)
{
    std::string full_path = "data/" + user_name + "/log.txt";

    if(user_name.compare(user_name_again) == 0)
    {
        dfile(full_path);
        wlog(user_name, "account has been banned");
    }
}

void unban_account(std::string user_name, std::string user_name_again)
{
    std::string full_path = "data/" + user_name + "/log.txt";

    if(user_name.compare(user_name_again) == 0)
    {
        dfile(full_path);
        wlog(user_name, "account has been unbanned");
    }
}

void change_pass(std::string user_name, std::string user_pass, std::string new_pass)
{
    std::string old_path = "data/" + user_name + "/" + user_pass + ".txt";
    std::string new_path = "data/" + user_name + "/" + new_pass + ".txt";

    std::string temp_str = rfile(old_path);
    dfile(old_path);
    wfile(new_path, temp_str);
}

// MADE BY @hanilr