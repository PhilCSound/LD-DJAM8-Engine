// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "engine.hpp"

int main()
{
	//Initialize MemPool and register some components.
	Engine engine;

	engine.Initialize();
	
	if (engine.IsRunning())
	{
		engine.Run();
	}

	//std::cout << "Hello CMake.\n";
	//std::cout << x->GetComponent(1);
	return 7;
}