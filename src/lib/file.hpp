// FILE FUNCTIONS LINKER (FILE LINKER)

#ifndef _FILE_HPP
#define _FILE_HPP

void wfile(std::string file_path, std::string file_string); // WRITE IN FILE

std::string rfile(std::string file_path); // READ IN FILE (ONLY FIRST LINE)

void cfile(std::string file_path); // CREATE A FILE

void dfile(std::string file_path); // DELETE A FILE

void wlog(std::string user_name, std::string log); // WRITE LOG

#endif // MADE BY @hanilr
