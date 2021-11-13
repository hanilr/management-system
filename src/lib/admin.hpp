// ADMIN FUNCTIONS LINKER (ADMIN LINKER)

#ifndef _ADMIN_HPP
#define _ADMIN_HPP

void create_account(std::string user_name, std::string user_pass, std::string user_pass_again);

void delete_account(std::string user_name, std::string user_name_again);

int freeze_check(std::string user_name);

int ban_check(std::string user_name);

void ban_account(std::string user_name, std::string user_name_again);

void unban_account(std::string user_name, std::string user_name_again);

void change_pass(std::string user_name, std::string user_pass, std::string new_pass);

#endif // FUNCTION NAMES ARE VERY CLEAR SO I DIDN'T WRITE ANY COMMENT IN HERE

// MADE BY @hanilr