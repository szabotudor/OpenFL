//This is a test file used when debugging the library. You shouldn't be including this in your project
#include"openfl.hpp"
#include<iostream>

int main(int argc, char* args[]) {
	OpenFL file{ RWType::READ, "hello.txt" };
	std::cout << file.fileContents;
}