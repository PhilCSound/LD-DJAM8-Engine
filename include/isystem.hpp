#pragma once
#include "componentmanager.hpp"
#include "SFML/Graphics.hpp"
#include "engine.hpp"

class Engine;

class ISystem
{
public:
	ISystem(bool multiThreadSafe = false);

	virtual void Initialize(Engine* eng) = 0;
	virtual void PreUpdate(Engine* eng) = 0;
	virtual void Update(Engine* eng) = 0;
	virtual void LateUpdate(Engine* eng) = 0;
	virtual void Render(sf::RenderTarget& targ, Engine* eng) = 0;

	const bool IsMultiThreadSafe() const;
	void SetMultiThreadSafety(bool isSafe);

protected:
	bool m_multiThreadSafe = false;
	
};