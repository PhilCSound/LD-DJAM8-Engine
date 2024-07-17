#pragma once
#include "engine.hpp"

class Engine;

class IScene
{
public:
	virtual void Initialize(std::shared_ptr<Engine> eng) = 0;
	virtual void OnSceneDestroy(std::shared_ptr<Engine> eng) = 0;
	virtual void Update(std::shared_ptr<Engine> eng) = 0;

protected:

};