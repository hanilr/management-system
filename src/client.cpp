// MAIN SECTION (MAIN)

#include <iostream>

#include "lib/file.hpp"
#include "lib/config.hpp"
#include "lib/user.hpp"
#include "lib/admin.hpp"
#include "lib/ui.hpp"

void top_menu(int temp_width, std::string mtitle, std::string msubtitle)
{
    clrscr();
    repeater("_", temp_width);
    nline(1);
    in_center(mtitle); // TITLE
    nline(1);

    in_center(msubtitle); // SUBTITLE
    repeater("_", temp_width);
    nline(1);
    nline(1);
}

void bottom_menu(int temp_width)
{
    std::string cversion = check_conf("version");
    std::string cwebsite = check_conf("website");
    
    nline(3);
    std::cout << " (e) EXIT";
    repeater(" ", temp_width-22);
    std::cout << "FEEDBACK (f) ";
    nline(1);

    repeater("_", temp_width);
    nline(1);
    // VERSION & WEBSITE

    std::cout << " " << cwebsite;
    repeater(" ", temp_width-cversion.length()-cwebsite.length()-2);
    std::cout << cversion << " " << std::endl;

    // VERSION & WEBSITE
    repeater("_", temp_width);
    nline(1);
    std::cout << " |> ";
}

std::string user_menu(std::string user_name, std::string user_pass, int temp_width)
{
    std::string temp_select;
    std::string ctitle = check_conf("title");
    std::string csubtitle = check_conf("subtitle");

    top_menu(temp_width, ctitle, csubtitle);
    // CHOICES

    category(" (1) FETCH VALUE", "FREEZE ACCOUNT (3) ", 35, 2, temp_width);
    category(" (2) CHANGE VALUE", "UNFREEZE ACCOUNT (4) ", 38, 0, temp_width);

    // CHOICES
    bottom_menu(temp_width);
    std::cin >> temp_select;

    return temp_select;
}

std::string first_menu(std::string user_name, std::string user_pass, int temp_width)
{
    std::string temp_select;
    std::string temp_value = fetch_value(user_name, user_pass);

    top_menu(temp_width, "VALUE:", temp_value);
    // CHOICES

    nline(1);
    category(" (1) CHANGE VALUE", "BACK TO MENU (2) ", 34, 0, temp_width);

    // CHOICES
    bottom_menu(temp_width);
    std::cin >> temp_select;

    return temp_select;
}

std::string second_menu(std::string user_name, std::string user_pass, int temp_width)
{
    std::string temp_select;
    std::string temp_value = fetch_value(user_name, user_pass);
    std::string temp_str = " (1) CHANGE INSTEAD OF [" + temp_value + "]";

    top_menu(temp_width, "CHANGE VALUE", "Use first choice to change value.");
    // CHOICES

    nline(1);
    category(temp_str, "BACK TO MENU (2) ", temp_value.length()+42, 0, temp_width);

    // CHOICES
    bottom_menu(temp_width);
    std::cin >> temp_select;

    return temp_select;
}

std::string third_menu(std::string user_name, std::string user_pass, int temp_width)
{
    std::string temp_select;
    std::string temp_value = fetch_value(user_name, user_pass);

    top_menu(temp_width, "FREEZE ACCOUNT", "Are you sure you want to freeze your account?");
    // CHOICES

    nline(1);
    category(" (1) FREEZE THE ACCOUNT", "BACK TO MENU (2) ", 40, 0, temp_width);

    // CHOICES
    bottom_menu(temp_width);
    std::cin >> temp_select;

    return temp_select;
}

std::string fourth_menu(std::string user_name, std::string user_pass, int temp_width)
{
    std::string temp_select;
    std::string temp_value = fetch_value(user_name, user_pass);

    top_menu(temp_width, "UNFREEZE ACCOUNT", "Are you sure you want to unfreeze your account?");
    // CHOICES

    nline(1);
    category(" (1) UNFREEZE THE ACCOUNT", "BACK TO MENU (2) ", 40, 0, temp_width);

    // CHOICES
    bottom_menu(temp_width);
    std::cin >> temp_select;

    return temp_select;
}

int main()
{
    std::string cwidth = check_conf("terminal-width");
    int count = 1, temp_width;
    std::string usr, pass, temp_str, temp_select;
    sscanf(cwidth.c_str(), "%d", &temp_width);
    
    // LOGIN SCREEN
    top_menu(temp_width, "LOG IN", "Please enter your username and password.");
    std::cout << "USERNAME: ";
    std::cin >> usr;
    std::cout << "PASSWORD: ";
    std::cin >> pass;

    if(freeze_check(usr) == 1) { poster("YOUR ACCOUNT IS FROZEN"); }
    else if(ban_check(usr) == 1)
    {
        poster("YOUR ACCOUNT HAS BAN");
        return 1;
    }
    else { poster("FREEZE AND BAN CHECK IS SUCCESS"); }


    std::string full_path = "data/" + usr + "/" + pass + ".txt";
    temp_str = rfile(full_path);
    if(temp_str.compare("") == 0)
    {
        top_menu(temp_width, "LOG IN FAILED", "Your username or password is incorrect!");
        return 0;
    }
    // LOGIN SCREEN
    
    // LOOP
    while(0 < count)
    {
        temp_select = user_menu(usr, pass, temp_width);
        if(temp_select == "1")
        {
            std::string temp_choice = first_menu(usr, pass, temp_width);
            if(temp_select == "1")
            {
                std::string answer, full_path = "data/" + usr + "/" + pass + ".txt";
                clrscr();
                top_menu(temp_width, "ENTER VALUE", "Please enter new value.");
                std::cout << " [ (e) exit ] |> ";
                std::cin >> answer;

                dfile(full_path);
                wfile(full_path, answer);
            }
            else if(temp_select == "e") { count -=1; }
            else if(temp_select == "f") { feedback(); }
        }
        else if(temp_select == "2")
        {
            temp_select = second_menu(usr, pass, temp_width);
            if(temp_select == "1")
            {
                std::string answer, full_path = "data/" + usr + "/" + pass + ".txt";
                clrscr();
                top_menu(temp_width, "ENTER VALUE", "Please enter new value.");
                std::cout << " |> ";
                std::cin >> answer;

                if(answer == "e") { second_menu(usr ,pass, temp_width); }
                dfile(full_path);
                wfile(full_path, answer);
            }
            else if(temp_select == "e") { count -=1; }
            else if(temp_select == "f") { feedback(); }
        }
        else if(temp_select == "3")
        {
            temp_select = third_menu(usr, pass, temp_width);
            if(temp_select == "1")
            {
                freeze_account(usr);
            }
            else if(temp_select == "e") { count -=1; }
            else if(temp_select == "f") { feedback(); }
        }
        else if(temp_select == "4")
        {
            temp_select = fourth_menu(usr, pass, temp_width);
            if(temp_select == "1") { unfreeze_account(usr); }
            else if(temp_select == "e") { count -=1; }
            else if(temp_select == "f") { feedback(); }
        }
        else if(temp_select == "e") { count -=1; }
        else if(temp_select == "f") { feedback(); }
    }
    // LOOP
    return 0;
} // MADE BY @hanilr
