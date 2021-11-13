// CONFIG SECTION (CONFIG)

#include <iostream>

#include "file.hpp"
#include "config.hpp"

std::string check_conf(std::string conf_name)
{
    std::string full_path = "conf/" + conf_name + ".txt";
    std::string temp_str = rfile(full_path);

    return temp_str;
} // FETCH VALUE WITH "std::string var = check_conf()"

void reset_conf(void)
{
    #ifdef _WIN32
        std::string command = "cd conf & del *.txt";
        system(command.c_str());
    #elif __unix__
        std::string command = "cd conf & rm *.txt";
        system(command.c_str());
    #endif

    wfile("conf/feedback.txt", "https://www.github.com/hanilr/management-system/issues");
    wfile("conf/subtitle.txt", "General purpose management system. Written in c++. Made by @hanilr.");
    wfile("conf/title.txt", "MANAGEMENT-SYSTEM");
    wfile("conf/version.txt", "v1.0");
    wfile("conf/website.txt", "https://www.github.com/hanilr/management-system");\
    wfile("conf/terminal-width.txt", "120");
    wfile("conf/terminal-height.txt", "30");
} 

void add_conf(std::string conf_name, std::string conf_set)
{
    std::string full_path = "conf/" + conf_name + ".txt";
    wfile(full_path, conf_set);
} 

void del_conf(std::string conf_name)
{
    std::string full_path = "conf/" + conf_name + ".txt";
    dfile(full_path);
} 

void change_conf(std::string conf_name, std::string conf_set)
{
    std::string full_path = "conf/" + conf_name + ".txt";

    dfile(full_path);
    wfile(full_path, conf_set);
} 

// MADE BY @hanilr