#pragma once
#include "componentmanager.hpp"
#include "entity.hpp"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "systemmanager.hpp"
#include "systems/oscillatepositionsystem.hpp"

class SystemManager;

class Engine
{
public:
	Engine() = default;

	Entity CreateEntity();
	void Initialize(const sf::VideoMode& vidMode, const std::string& windowName);
	const bool IsRunning() const;
	void Run();

	std::shared_ptr<ComponentManager> GetComponentManager() const;
	std::shared_ptr<SystemManager> GetSystemManager() const;

private:
	std::shared_ptr<ComponentManager> m_compMan;
	std::shared_ptr<SystemManager> m_systemManager;
	bool m_isRunning = false;
	sf::RenderWindow m_renderWindow;
};