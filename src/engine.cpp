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
	m_systemManager = std::make_shared<SystemManager>(32);
}

const bool Engine::IsRunning() const
{
	return m_isRunning;
}

void Engine::Run()
{
	std::cout << "\nNumSystems: " << m_systemManager->GetNumberOfRegSystems();

	while (m_renderWindow.isOpen())
	{
		m_sceneMan->UpdateScenes(this);
		m_systemManager->RunSystems(m_compMan);
	}

}

std::shared_ptr<ComponentManager> Engine::GetComponentManager() const
{
	return m_compMan;
}

std::shared_ptr<SceneManager> Engine::GetSceneManager() const
{
	return m_sceneMan;
}

std::shared_ptr<SystemManager> Engine::GetSystemManager() const
{
	return m_systemManager;
}
