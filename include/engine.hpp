#pragma once
#include "componentmanager.hpp"
#include "entity.hpp"
#include <iostream>

class Engine
{
public:
	Engine() = default;

	Entity CreateEntity();
	void Initialize();
	const bool IsRunning() const;
	void Run();

private:
	std::shared_ptr<ComponentManager> m_compMan;
	bool m_isRunning = false;
};