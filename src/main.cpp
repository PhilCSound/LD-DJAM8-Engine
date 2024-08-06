// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "engine.hpp"
#include "systems/oscillatepositionsystem.hpp"
#include "scenes/testscene.hpp"

int main()
{
	//Initialize MemPool and register some components.
	Engine engine;

	engine.Initialize({800, 600}, "DJAM ENGINE");

	//Register Components
	auto compMan = engine.GetComponentManager();
	compMan->RegisterComponent<CPosition>();
	compMan->RegisterComponent<double>();

	//Register Osc System
	engine.GetSystemManager()->RegisterSystem("osc", new OscillatePositionSystem{});
	
	//Load Scene
	engine.GetSceneManager()->QueueSceneChange(new TestScene{});

	if (engine.IsRunning())
	{
		engine.Run();
	}

	return 7;
}