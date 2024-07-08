// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "engine.hpp"

int main()
{
	//Initialize MemPool and register some components.
	Engine engine;

	engine.Initialize({800, 600}, "DJAM ENGINE");
	
	if (engine.IsRunning())
	{
		engine.Run();
	}

	return 7;
}