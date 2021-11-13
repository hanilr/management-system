// TERMINAL UI SECTION (UI)

#include <iostream>

#include "file.hpp"
#include "config.hpp"
#include "ui.hpp"



void nline(int count) { for(count; 0<count; count-=1) { std::cout << std::endl; } }

void clrscr(void)
{
    #ifdef _WIN32
        system("cls");
    #elif __unix__
        system("clear");
    #endif
}

void repeater(std::string temp_str, int count)
{
    for(count; 0<count; count-=1) { std::cout << temp_str; }
} // NEED TO BE IN NEW LINE BEFORE USE

void in_center(std::string temp_str)
{
    std::string terminal_width = rfile("conf/terminal-width.txt");
    int temp_width, temp_len = temp_str.length();
    sscanf(terminal_width.c_str(), "%d", &temp_width);

    if(temp_width % 2 == 0) { temp_width = temp_width/2; }
    else { temp_width = (temp_width-1)/2; }

    if(temp_len % 2 == 0) { temp_len = temp_len/2; }
    else { temp_len = (temp_len-1)/2; }

    repeater(" ", temp_width-temp_len);
    std::cout << temp_str << std::endl;
} // WILL BE NEW LINE AFTER USE

void feedback(void)
{
    std::string cwebsite = check_conf("website");

    #ifdef _WIN32
        std::string full_path = "start " + cwebsite;
        system(full_path.c_str());
    #elif __unix__
        std::string full_path = "xdg-open " + cwebsite;
        system(full_path.c_str());
    #endif
}

void poster(std::string temp_str)
{
    std::string cwidth = check_conf("terminal-width");
    int temp_width;
    sscanf(cwidth.c_str(), "%d", &temp_width);

    clrscr();
    repeater("_", temp_width);
    nline(1);
    in_center(temp_str);
    repeater("_", temp_width);
    std::cout << " [ (e) Exit ] |> ";
}

std::string menu(std::string commemnt, std::string choice)
{
    std::string cwidth = check_conf("terminal-width");

    int temp_width;
    std::string temp_select, temp_str = " (1) " + choice;
    sscanf(cwidth.c_str(), "%d", &temp_width);

    clrscr();
    repeater("_", temp_width);
    nline(1);
    in_center(commemnt);
    repeater("_", temp_width);
    nline(2);
    // CHOICES

    category(temp_str, "BACK TO MENU (2) ", choice.length()+22, 3, temp_width);
    category(" (e) EXIT", "FEEDBACK (f) ", 22, 0, temp_width);

    // CHOICES
    repeater("_", temp_width);
    std::cout << " |> ";
    std::cin >> temp_select;

    return temp_select;
}

void category(std::string first_choice, std::string second_choice, int result_int, int line ,int temp_width)
{
    std::cout << first_choice;
    repeater(" ", temp_width-result_int);
    std::cout << second_choice;
    nline(line);
}

// MADE BY @hanilr