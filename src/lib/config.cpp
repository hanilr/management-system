// CONFIG SECTION (CONFIG)

#include <iostream>

#include "file.hpp"
#include "config.hpp"
using namespace std;

string check_conf(string conf_name)
{
    string full_path = "conf/" + conf_name + ".txt";
    string temp_str = rfile(full_path);

    return temp_str;
} // FETCH VALUE WITH "string var = check_conf()"

int reset_conf(void)
{
    #ifdef _WIN32
        string command = "cd conf & del *.txt";
        system(command.c_str());
    #elif __unix__
        string command = "cd conf & rm *.txt";
        system(command.c_str());
    #endif

    wfile("conf/feedback.txt", "https://www.github.com/hanilr/management-system/issues");
    wfile("conf/subtitle.txt", "General purpose management system. Written in c++. Made by @hanilr.");
    wfile("conf/title.txt", "MANAGEMENT-SYSTEM");
    wfile("conf/version.txt", "v1.0");
    wfile("conf/website.txt", "https://www.github.com/hanilr/management-system");\
    wfile("conf/terminal-width.txt", "120");
    wfile("conf/terminal-height.txt", "30");

    return 0;
} // CHECK ISSUES WITH "int var = reset_conf()"

int add_conf(string conf_name, string conf_set)
{
    string full_path = "conf/" + conf_name + ".txt";
    wfile(full_path, conf_set);

    return 0;
} // CHECK ISSUES WITH "int var = add_conf()"

int del_conf(string conf_name)
{
    string full_path = "conf/" + conf_name + ".txt";
    dfile(full_path);

    return 0;
} // CHECK ISSUES WITH "int var = del_conf()"

int change_conf(string conf_name, string conf_set)
{
    string full_path = "conf/" + conf_name + ".txt";

    dfile(full_path);
    wfile(full_path, conf_set);

    return 0;
} // CHECK ISSUES WITH "int var = change_conf()"
