// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "engine.hpp"
#include "systems/oscillatepositionsystem.hpp"

int main()
{
	//Initialize MemPool and register some components.
	Engine engine;

	engine.Initialize({800, 600}, "DJAM ENGINE");
	engine.GetSystemManager()->RegisterSystem("osc", new OscillatePositionSystem{});
	if (engine.IsRunning())
	{
		engine.Run();
	}

	return 7;
}