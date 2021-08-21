// CODE TEST SECTION (TEST)

#include <iostream>

#include "lib/file.hpp"
#include "lib/config.hpp"
#include "lib/user.hpp"
#include "lib/admin.hpp"
#include "lib/ui.hpp"
using namespace std;

string temp_str;
int temp_int;

int main()
{
    // FILE
    wfile("foo.txt", "bar"); // WRITE IN A FILE
    temp_str = rfile("foo.txt"); // READ A FILE
    cfile("foo.txt"); // CREATE A FILE
    dfile("foo.txt"); // DELETE A FILE
    wlog("foo", "bar"); // WRITE LOG
    // FILE

    // ADMIN
    create_account("foo", "bar", "bar"); // CREATE AN ACCOUNT
    delete_account("foo", "foo"); // DELETE AN ACCOUNT
    temp_int = freeze_check("foo"); // IS ACCOUNT HAS FREEZE
    temp_int = ban_check("foo"); // IS ACCOUNT HAS BAN
    ban_account("foo", "foo"); // BAN AN ACCOUNT
    unban_account("foo", "foo"); // UNBAN AN ACCOUNT
    change_pass("foo", "bar", "new"); // CHANGE AN ACCOUNT PASSWORD
    // ADMIN

    // USER
    temp_str = fetch_value("foo", "bar"); // FETCH USER VALUE
    change_value("foo", "bar", "value"); // CHANGE USER VALUE
    freeze_account("foo"); // FREEZE AN ACCOUNT
    unfreeze_account("foo"); // UNFREEZE AN ACCOUNT
    // USER

    // CONFIG
    temp_str = check_conf("foo"); // RETURN CONFIG
    reset_conf(); // RESET ALL CONFIG
    add_conf("foo", "bar"); // ADD A CONFIG
    del_conf("foo"); // DELETE A CONFIG
    change_conf("foo", "bar"); // CHANGE A CONFIG SETTING
    // CONFIG

    // UI
    nline(42); // NEW LINE
    clrscr(); // CLEAR SCREEN
    repeater("foo", 42); // REPEAT A STRING INT TIMES
    in_center("foo"); // PUT IT IN CENTER
    feedback(); // DIRECT TO WEBSITE
    poster("foo"); // COOL FUNCTION
    menu("foo", "bar"); // SIMPLE MENU
    category("foo", "bar", 6, 2 , 120); // SIMPLE CATEGORY (120 is default value of terminal width)
    // UI
    return 0;
} // NOW 28 COMMAND CAN USE
