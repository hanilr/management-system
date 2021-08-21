// ADMIN CONTROL SECTION (CONTROL)

#include <iostream>

#include "lib/file.hpp"
#include "lib/config.hpp"
#include "lib/admin.hpp"
#include "lib/ui.hpp"
using namespace std;

string temp_select, null;

void top_menu(int temp_width)
{
    clrscr();
    repeater("_", temp_width);
    in_center("CONTROL PANEL");
    repeater("_", temp_width);
    nline(1);
}

void bottom_menu(int temp_width)
{
    repeater("_", temp_width);
    in_center("IF YOU GOT ANY ISSUE PLEASE CONTACT WITH FEEDBACK LINK.");
    repeater("_", temp_width);
    cout << " |> ";
}

string control_menu(int temp_width)
{
    top_menu(temp_width);
    // CHOICES

    category(" (1) CREATE ACCOUNT", "RESET CONFIG (7) ", 36, 2, temp_width);
    category(" (2) DELETE ACCOUNT", "ADD CONFIG (8) ", 34, 2, temp_width);
    category(" (3) BAN ACCOUNT", "DELETE CONFIG (9) ", 34, 2, temp_width);
    category(" (4) UNBAN ACCOUNT", "CHECK CONFIG (10) ", 36, 2, temp_width);
    category(" (5) BAN CHECK", "CHANGE CONFIG (11) ", 33, 2, temp_width);
    category(" (6) FREEZE CHECK", "CHANGE PASSWORD (12) ", 38, 3, temp_width);
    category(" (f) FEEDBACK", "", 0, 1, temp_width);

    // CHOICES
    bottom_menu(temp_width);
    cin >> temp_select;

    return temp_select;
}

int main()
{
    string cwidth = check_conf("terminal-width");
    int temp_width;

    NEW_CONTROL:
    int count = 1;
    sscanf(cwidth.c_str(), "%d", &temp_width);
    // LOOP
    while(0 < count)
    {
        temp_select = control_menu(temp_width);
        if(temp_select == "1")
        {
            string temp_choice = menu("DO YOU WANT TO CREATE AN ACCOUNT?", "CREATE AN ACCOUNT");
            if(temp_choice == "1")
            {
                string temp_usr, temp_pass, temp_pass_again;

                clrscr();
                repeater("_", temp_width);
                in_center("PLEASE ENTER ACCOUNT INFORMATINON");
                repeater("_", temp_width);
                nline(2);

                cout << "USERNAME: ";
                cin >> temp_usr;
                cout << "PASSWORD: ";
                cin >> temp_pass;
                cout << "PASSWORD AGAIN: ";
                cin >> temp_pass_again;
                create_account(temp_usr, temp_pass, temp_pass_again);
            }
            else if(temp_choice == "e") { count -=1; }
            else if(temp_choice == "f") { feedback(); }
        }
        else if(temp_select == "2")
        {
            string temp_choice = menu("DO YOU WANT TO DELETE AN ACCOUNT?", "DELETE AN ACCOUNT");
            if(temp_choice == "1")
            {
                string temp_usr, temp_usr_again;

                clrscr();
                repeater("_", temp_width);
                in_center("PLEASE ENTER USERNAME");
                repeater("_", temp_width);
                nline(2);

                cout << "USERNAME: ";
                cin >> temp_usr;
                cout << "USERNAME AGAIN: ";
                cin >> temp_usr_again;
                delete_account(temp_usr, temp_usr_again);
            }
            else if(temp_choice == "e") { count -=1; }
            else if(temp_choice == "f") { feedback(); }
        }
        else if(temp_select == "3")
        {
            string temp_choice = menu("DO YOU WANT TO BAN AN ACCOUNT?", "BAN AN ACCOUNT");
            if(temp_choice == "1")
            {
                string temp_usr, temp_usr_again;

                clrscr();
                repeater("_", temp_width);
                in_center("PLEASE ENTER USERNAME");
                repeater("_", temp_width);
                nline(2);

                cout << "USERNAME: ";
                cin >> temp_usr;
                cout << "USERNAME AGAIN: ";
                cin >> temp_usr_again;
                ban_account(temp_usr, temp_usr_again);
            }
            else if(temp_choice == "e") { count -=1; }
            else if(temp_choice == "f") { feedback(); }
        }
        else if(temp_select == "4")
        {
            string temp_choice = menu("DO YOU WANT TO UNBAN AN ACCOUNT?", "UNBAN AN ACCOUNT");
            if(temp_choice == "1")
            {
                string temp_usr, temp_usr_again;

                clrscr();
                repeater("_", temp_width);
                in_center("PLEASE ENTER USERNAME");
                repeater("_", temp_width);
                nline(2);

                cout << "USERNAME: ";
                cin >> temp_usr;
                cout << "USERNAME AGAIN: ";
                cin >> temp_usr_again;
                unban_account(temp_usr, temp_usr_again);
            }
            else if(temp_choice == "e") { count -=1; }
            else if(temp_choice == "f") { feedback(); }
        }
        else if(temp_select == "5")
        {
            string temp_choice = menu("DO YOU WANT TO BAN CHECK AN ACCOUNT?", "BAN CHECK");
            if(temp_choice == "1")
            {
                string temp_usr;

                clrscr();
                repeater("_", temp_width);
                in_center("PLEASE ENTER USERNAME");
                repeater("_", temp_width);
                nline(2);

                cout << "USERNAME: ";
                cin >> temp_usr;
                int temp_value = ban_check(temp_usr);
                if(temp_value == 1)
                {
                    poster("THE ACCOUNT IS BLOCKED");
                    cin >> null;
                }
                else
                {
                    poster("THE ACCOUNT IS UNBLOCKED");
                    cin >> null;
                }
            }
            else if(temp_choice == "e") { count -=1; }
            else if(temp_choice == "f") { feedback(); }
        }
        else if(temp_select == "6")
        {
            string temp_choice = menu("DO YOU WANT TO CHECKING FREEZE AN ACCOUNT?", "FREEZE CHECK");
            if(temp_choice == "1")
            {
                string temp_usr;

                clrscr();
                repeater("_", temp_width);
                in_center("PLEASE ENTER USERNAME");
                repeater("_", temp_width);
                nline(2);

                cout << "USERNAME: ";
                cin >> temp_usr;
                int temp_value = freeze_check(temp_usr);
                if(temp_value == 1)
                {
                    poster("THE ACCOUNT IS FROZEN");
                    cin >> null;
                }
                else
                {
                    poster("THE ACCOUNT IS NOT FROZEN");
                    cin >> null;
                }
            }
            else if(temp_choice == "e") { count -=1; }
            else if(temp_choice == "f") { feedback(); }
        }
        else if(temp_select == "7")
        {
            string temp_choice = menu("DO YOU WANT TO RESET WHOLE CONFIG?", "RESET CONFIG");
            if(temp_choice == "1")
            {
                reset_conf();
                poster("CONF FOLDER HAS BEEN RESETED");
                cin >> null;
            }
            else if(temp_choice == "e") { count -=1; }
            else if(temp_choice == "f") { feedback(); }
        }
        else if(temp_select == "8")
        {
            string temp_choice = menu("DO YOU WANT TO ADD A CONFIG?", "ADD A CONFIG");
            if(temp_choice == "1")
            {
                string temp_name, temp_set;

                clrscr();
                repeater("_", temp_width);
                in_center("PLEASE ENTER NEW CONFIG INFORMATIONS");
                repeater("_", temp_width);
                nline(2);

                cout << "CONFIG NAME: ";
                cin >> temp_name;
                cout << "CONFIG SETTING: ";
                cin >> temp_set;
                add_conf(temp_name, temp_set);
                poster("CONFIG HAS BEEN ADDED");
                cin >> null;
            }
            else if(temp_choice == "e") { count -=1; }
            else if(temp_choice == "f") { feedback(); }
        }
        else if(temp_select == "9")
        {
            string temp_choice = menu("DO YOU WANT TO DELETE A CONFIG?", "DELETE A CONFIG");
            if(temp_choice == "1")
            {
                string temp_name;

                clrscr();
                repeater("_", temp_width);
                in_center("PLEASE ENTER CONFIG NAME");
                repeater("_", temp_width);
                nline(2);

                cout << "CONFIG NAME: ";
                cin >> temp_name;
                del_conf(temp_name);
                poster("CONFIG HAS BEEN DELETED");
                cin >> null;
            }
            else if(temp_choice == "e") { count -=1; }
            else if(temp_choice == "f") { feedback(); }
        }
        else if(temp_select == "10")
        {
            string temp_choice = menu("DO YOU WANT TO CHECK A CONFIG?", "CHECK CONFIG");
            if(temp_choice == "1")
            {
                string temp_name, temp_value;

                clrscr();
                repeater("_", temp_width);
                in_center("PLEASE ENTER CONFIG NAME");
                repeater("_", temp_width);
                nline(2);

                cout << "CONFIG NAME: ";
                cin >> temp_name;
                temp_value = check_conf(temp_name);
                poster(temp_value);
                cin >> null;
            }
            else if(temp_choice == "e") { count -=1; }
            else if(temp_choice == "f") { feedback(); }
        }
        else if(temp_select == "11")
        {
            string temp_choice = menu("DO YOU WANT TO CHANGE A CONFIG?", "CHANGE A CONFIG");
            if(temp_choice == "1")
            {
                string temp_name, temp_set;

                clrscr();
                repeater("_", temp_width);
                in_center("PLEASE ENTER CONFIG NAME AND NEW SETTING");
                repeater("_", temp_width);
                nline(2);

                cout << "CONFIG NAME: ";
                cin >> temp_name;
                cout << "CONFIG SETTING: ";
                cin >> temp_set;
                change_conf(temp_name, temp_set);
                poster("CONFIG HAS BEEN UPDATED");
                cin >> null;
            }
            else if(temp_choice == "e") { count -=1; }
            else if(temp_choice == "f") { feedback(); }
        }
        else if(temp_select == "12")
        {
            string temp_choice = menu("DO YOU WANT TO CHANGE PASSWORD AN ACCOUNT?", "CHANGE PASSWORD AN ACCOUNT?");
            if(temp_choice == "1")
            {
                string temp_usr, temp_pass, temp_pass_again;

                clrscr();
                repeater("_", temp_width);
                in_center("PLEASE ENTER ACCOUNT INFORMATIONS");
                repeater("_", temp_width);
                nline(2);

                cout << "USERNAME: ";
                cin >> temp_usr;
                cout << "PASSWORD: ";
                cin >> temp_pass;
                cout << "PASSWORD AGAIN: ";
                cin >> temp_pass_again;
                change_pass(temp_usr, temp_pass, temp_pass_again);
                poster("THE ACCOUNT PASSWORD HAS BEEN UPDATED");
                cin >> null;
            }
            else if(temp_choice == "e") { count -=1; }
            else if(temp_choice == "f") { feedback(); }
        }
        else if(temp_select == "f") { feedback(); }
    }
    // LOOP
    goto NEW_CONTROL;
    return 0;
}
