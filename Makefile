# MAKEFILE IS OPTIMIZED FOR ONLY WINDOWS AND UNIX

.PHONY: run user control test clear
user_name = client
control_name = control

path = src/lib/

control = $(path)file.cpp $(path)config.cpp $(path)admin.cpp $(path)ui.cpp
user = $(path)file.cpp $(path)config.cpp $(path)user.cpp $(path)admin.cpp $(path)ui.cpp
test = $(path)file.cpp $(path)admin.cpp $(path)user.cpp $(path)config.cpp $(path)ui.cpp

ifeq ($(OS),Windows_NT)

run: # REQUIRED "c++" COMPILER
	c++ src/$(user_name).cpp $(user) -o $(user_name).exe
	c++ src/$(control_name).cpp $(control) -o $(control_name).exe

user:
	c++ src/$(user_name).cpp $(user) -o $(user_name).exe

control:
	c++ src/$(control_name).cpp $(control) -o $(control_name).exe

test:
	c++ src/test.cpp $(test) -o test.exe

clear: # DELETE EVERY ".exe" FILE
	del *.exe

else

run: # REQUIRED "g++" COMPILER
	g++ src/$(user_name).cpp $(user) -o $(user_name)
	g++ src/$(control_name).cpp $(control) -o $(control_name)

user:
	g++ src/$(user_name).cpp $(user) -o $(user_name)

control:
	g++ src/$(control_name).cpp $(control) -o $(control_name)

test:
	g++ src/test.cpp $(test) -o test

clear: # REMOVE ALL COMPLIED FILES
	rm $(user_name)
	rm $(control_name)
	rm test

endif
