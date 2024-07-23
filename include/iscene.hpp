#pragma once
#include "engine.hpp"

class Engine;

class IScene
{
public:
	virtual void Initialize(Engine* eng) = 0;
	virtual void OnSceneDestroy(Engine* eng) = 0;
	virtual void Update(Engine* eng) = 0;

protected:

};