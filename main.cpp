#include"openfl.hpp"


int main(int argc, char* args[]) {
	OpenFL file{ RWType::READ, "hello.txt" };
	std::cout << file.fileContents;
}