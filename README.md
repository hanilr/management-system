# MANAGEMENT SYSTEM
General purpose management system. Written in c++ standard library.

* [About The Project](#about-the-project)
* [Compile And Running](#compile-and-running)
* [Usage](#usage)


# ABOUT THE PROJECT
I made bank management system in c programming language and later I start to learn c++. So I decide to make another management system but with c++ and this time I learnt my faults so I do but better. Also it will be general purpose and has a config folder so developers can change a config or all file for they desire. So I built a general purpose and changable management system. By the way thats my first c++ project if you find any bug or bad writed code please leave a feedback in issues section.


## Images
The images taken from windows terminal.

### User after log in screen.
![user](https://user-images.githubusercontent.com/77579421/130335956-9f9e95f2-51fe-4d49-9993-ca3c765c322a.PNG)


### Admin screen.
![admin](https://user-images.githubusercontent.com/77579421/130335959-eb7fe7f0-b657-4254-95a0-fce4c3d5f1b8.PNG)



# COMPILE AND RUNNING

## Required environment:
### Windows:
MiniGW: ` https://sourceforge.net/projects/mingw/ `

GnuWin32: ` http://gnuwin32.sourceforge.net/ `


### Linux:
make: ` sudo [package-management] install make `

g++: ` sudo [package-management] install g++ `

## COMPILE: ` make `
User:  ` make user ` Compile only client executable file.

Control:  ` make control ` Compile only admin executable file.

Test:  ` make test ` Compile only test executable file.

Clear:  ` make clear ` Delete all compiled files.


## RUN: 
### Windows:
` client.exe ` for users.

` control.exe ` for admins.


### Linux
` ./client` for users.

` ./control ` for admins.

# USAGE
User: ` fetch_value() ` ` change_value() ` ` freeze_account() ` ` unfreeze_account() `    

Admin: ` create_account() ` ` delete_account() ` ` ban_account() ` ` unban_account() ` ` ban_check() ` ` freeze_check() ` ` reset_conf() ` ` add_conf() ` ` delete_conf() ` ` check_conf() ` ` change_conf() ` ` change_pass() ` 

## MY CODING FAULTS
1. Do not use ` using namespace std; ` especially in header files.

2. Do not use global variables.

3. Do use void instead of "int func() { return 0; }"

4. Avoid from goto.

5. Becareful about string arguments in functions.
