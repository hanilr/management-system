// FILE SECTION (FILE)

#include <iostream>
#include <fstream>

#include "file.hpp"

void wfile(std::string file_path, std::string file_string)
{
    std::ofstream write_file(file_path);
    write_file << file_string;

    write_file.close();
}

std::string rfile(std::string file_path)
{
    std::string file_string;
    std::ifstream read_file(file_path);

    std::getline(read_file, file_string);

    read_file.close();
    return file_string;
} // RECEIVE FILE RETURN WITH "string var = rfile()"

void cfile(std::string file_path)
{
    #ifdef _WIN32
        std::string command = "type nul >> " + file_path;
        system(command.c_str());
    #elif __unix__
        string command = "touch " + file_path;
        system(command.c_str());
    #endif
}

void dfile(std::string file_path) { remove(file_path.c_str()); } 

void wlog(std::string user_name, std::string log)
{
    std::string full_path = "data/" + user_name + "/log.txt";
    dfile(full_path);
    wfile(full_path, log);
}

// MADE BY @hanilr