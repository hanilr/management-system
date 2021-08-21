// CONFIG FUNCTIONS LINKER (CONFIG LINKER)

#ifndef _CONFIG_HPP
#define _CONFIG_HPP

#include <iostream>
using namespace std;

string check_conf(string conf_name);

int reset_conf(void);

int add_conf(string conf_name, string conf_set);

int del_conf(string conf_name);

int change_conf(string conf_name, string conf_set);

#endif // FUNCTION NAMES ARE VERY CLEAR SO I DIDN'T WRITE ANY COMMENT IN HERE
