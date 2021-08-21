// TERMINAL UI FUNCTIONS LINKER (UI LINKER)

#ifndef _UI_HPP
#define _UI_HPP

#include <iostream>
using namespace std;

void nline(int count); // NEW LINE (NEED "count" ARGUMENT)

void clrscr(void); // CLEAR SCREEN

void repeater(string temp_str, int count); // REPEAT A CHAR OR STRING

void in_center(string temp_str); // PUT A STRING TO THE CENTER OF LINE

void feedback(void); // DIRECT TO WEBSITE

void poster(string temp_str); // COOL FUNCTION

string menu(string commemnt, string choice); // SIMPLE MENU

void category(string first_choice, string second_choice, int result_int, int line ,int temp_width); // SIMPLE CATEGORY

#endif
