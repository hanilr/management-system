// USER SECTION (USER)

#include <iostream>

#include "file.hpp"

std::string fetch_value(std::string user_name, std::string user_pass)
{
    std::string full_path = "data/" + user_name + "/" + user_pass + ".txt";
    std::string temp_value = rfile(full_path);

    return temp_value;
} // CHECK ISSUES WITH "std::string var = fetch_value()"

void change_value(std::string user_name, std::string user_pass, std::string value)
{
    std::string full_path = "data/" + user_name + "/" + user_pass + ".txt";

    dfile(full_path);
    wfile(full_path, value);
}

void freeze_account(std::string user_name)
{
    std::string full_path = "data/" + user_name + "/log.txt";

    wlog(full_path, "account has been frozen");
}

void unfreeze_account(std::string user_name)
{
    std::string full_path = "data/" + user_name + "/log.txt";

    wlog(full_path, "account has been unfreeze");
}
