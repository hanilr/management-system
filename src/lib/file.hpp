// FILE FUNCTIONS LINKER (FILE LINKER)

#ifndef _FILE_HPP
#define _FILE_HPP

#include <iostream>
using namespace std;

int wfile(string file_path, string file_string); // WRITE IN FILE

string rfile(string file_path); // READ IN FILE (ONLY FIRST LINE)

int cfile(string file_path); // CREATE A FILE

int dfile(string file_path); // DELETE A FILE

int wlog(string user_name, string log); // WRITE LOG

#endif
