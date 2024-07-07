// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "entity.hpp"
#include "componentmanager.hpp"
int main()
{
	//Initialize MemPool and register some components.
	auto memPool = ComponentManager::GetInstance();
	memPool->RegisterComponent<int>();
	memPool->RegisterComponent<double>();

	Entity main_character = memPool->CreateEntity();
	main_character.AddComponent<int>(3);

	auto x = memPool->GetComponentArray<int>();
	std::cout << x->Size();
	x->GetComponent(0) += 25;
	std::cout << x->GetComponent(0) <<"\n";

	Entity main_character1 = memPool->CreateEntity();
	main_character1.AddComponent<int>(8);

	Entity main_character2 = memPool->CreateEntity();
	Entity main_character3 = memPool->CreateEntity();

	std::cout << "Hello CMake.\n";
	std::cout << x->GetComponent(1);
	return 4;
}