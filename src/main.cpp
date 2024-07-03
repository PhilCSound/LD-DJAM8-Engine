// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "entity.hpp"

int main()
{
	std::cout << "Hello CMake.\n";
	Entity main_character{ 2 };
	std::cout << main_character.Get_ID();
	return 0;
}
