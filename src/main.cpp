// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "entity.hpp"
#include "componentmanager.hpp"
int main()
{
	//Initialize MemPool and register some components.
	ComponentManager compMan;
	compMan.RegisterComponent<int>();
	compMan.RegisterComponent<double>();

	Entity main_character = compMan.CreateEntity();
	main_character.AddComponent<int>(3);

	auto x = compMan.GetComponentArray<int>();
	std::cout << x->Size();
	x->GetComponent(0) += 25;
	std::cout << x->GetComponent(0) <<"\n";

	Entity main_character1 = compMan.CreateEntity();
	main_character1.AddComponent<int>(8);

	Entity main_character2 = compMan.CreateEntity();
	Entity main_character3 = compMan.CreateEntity();

	std::cout << "Hello CMake.\n";
	std::cout << x->GetComponent(1);
	return 7;
}