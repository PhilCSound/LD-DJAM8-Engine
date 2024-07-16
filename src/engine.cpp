#pragma once
#include "engine.hpp"

Entity Engine::CreateEntity()
{
	return Entity(m_compMan->CreateEntityID(), m_compMan);
}

void Engine::Initialize(const sf::VideoMode& vidMode, const std::string& windowName)
{
	m_isRunning = true;
	m_renderWindow.create(vidMode, windowName);
	m_compMan = std::make_shared<ComponentManager>(1000, 24);
	m_compMan->RegisterComponent<CPosition>();
	m_compMan->RegisterComponent<double>();

	m_systemManager = std::make_shared<SystemManager>(32);
	m_systemManager->RegisterSystem("oscPos", new OscillatePositionSystem());

}

const bool Engine::IsRunning() const
{
	return m_isRunning;
}

void Engine::Run()
{
	Entity player = CreateEntity();
	Entity player2 = CreateEntity();
	player.AddComponent<CPosition>({300, 53});
	player.AddComponent<double>(3.346);
	player2.AddComponent<CPosition>({300, 346});
	player2.AddComponent<double>(43.546);
	std::cout << player.GetComponent<CPosition>().x;
	std::cout << "\nNumSystems: " << m_systemManager->GetNumberOfRegSystems();

	while (m_renderWindow.isOpen())
	{
		m_systemManager->RunSystems(m_compMan);
		std::cout << "Player 1: " << player.GetComponent<CPosition>().x << ", " << player.GetComponent<CPosition>().y << "\n";
		std::cout << "Player 2: " << player2.GetComponent<CPosition>().x << ", " << player2.GetComponent<CPosition>().y << "\n";
	}

}

std::shared_ptr<ComponentManager> Engine::GetComponentManager() const
{
	return m_compMan;
}

std::shared_ptr<SystemManager> Engine::GetSystemManager() const
{
	return m_systemManager;
}
