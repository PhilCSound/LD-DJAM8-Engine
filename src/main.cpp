// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "entity.hpp"
#include "memorypool.hpp"

int main()
{
	auto memPool = MemoryPool::GetInstance();

	Entity main_character = memPool->CreateEntity();
	Entity main_character1 = memPool->CreateEntity();
	Entity main_character2 = memPool->CreateEntity();
	Entity main_character3 = memPool->CreateEntity();

	std::cout << "Hello CMake.\n";
	std::cout << main_character3.Get_ID();
	return 0;
}