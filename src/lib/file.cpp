// FILE SECTION (FILE)

#include <iostream>
#include <fstream>

#include "file.hpp"
using namespace std;

int wfile(string file_path, string file_string)
{
    ofstream write_file(file_path);
    write_file << file_string;

    write_file.close();
    return 0;
} // CHECK ISSUES WITH "int var = wfile()"

string rfile(string file_path)
{
    string file_string;
    ifstream read_file(file_path);

    getline(read_file, file_string);

    read_file.close();
    return file_string;
} // RECEIVE FILE RETURN WITH "string var = rfile()"

int cfile(string file_path)
{
    #ifdef _WIN32
        string command = "type nul >> " + file_path;
        system(command.c_str());
    #elif __unix__
        string command = "touch " + file_path;
        system(command.c_str());
    #endif

    return 0;
}

int dfile(string file_path)
{
    remove(file_path.c_str());

    return 0;
} // RECEIVE FILE RETURN WITH "string var = dfile()"

int wlog(string user_name, string log)
{
    string full_path = "data/" + user_name + "/log.txt";
    dfile(full_path);
    wfile(full_path, log);

    return 0;
} // RECEIVE FILE RETURN WITH "string var = wlog()"
