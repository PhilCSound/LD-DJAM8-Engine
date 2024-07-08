#include "engine.hpp"

Entity Engine::CreateEntity()
{
	return Entity(m_compMan->CreateEntityID(), m_compMan);
}

void Engine::Initialize()
{
	m_isRunning = true;
	m_compMan = std::make_shared<ComponentManager>(1000, 24);
	m_compMan->RegisterComponent<int>();
	m_compMan->RegisterComponent<double>();
}

const bool Engine::IsRunning() const
{
	return m_isRunning;
}

void Engine::Run()
{
	Entity player = CreateEntity();
	Entity player2 = CreateEntity();
	player.AddComponent<double>(3.346);
	player2.AddComponent<int>(6);
	player2.AddComponent<double>(43.546);


	std::cout << player.GetComponent<int>();

}