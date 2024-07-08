#pragma once
#include "componentmanager.hpp"
#include "entity.hpp"
#include <iostream>
#include "SFML/Graphics.hpp"

class Engine
{
public:
	Engine() = default;

	Entity CreateEntity();
	void Initialize(const sf::VideoMode& vidMode, const std::string& windowName);
	const bool IsRunning() const;
	void Run();

private:
	std::shared_ptr<ComponentManager> m_compMan;
	bool m_isRunning = false;
	sf::RenderWindow m_renderWindow;
};