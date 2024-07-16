#pragma once
#include "systems/oscillatepositionsystem.hpp"

void OscillatePositionSystem::Initialize(std::shared_ptr<ComponentManager> cMan)
{
}

void OscillatePositionSystem::PreUpdate(std::shared_ptr<ComponentManager> cMan)
{
}

void OscillatePositionSystem::Update(std::shared_ptr<ComponentManager> cMan)
{
	auto compArray = cMan->GetComponentArray<CPosition>();
	for (int i = 0; i < compArray->Size(); i++)
	{
		if (compArray->ContainsComponent(i))
		{
			auto& comp = compArray->GetComponent(i);
			comp.x += 10;
			comp.y -= 6;
			if (comp.x >= 1000)
				comp.x = -1000;
			if (comp.y <= -1000)
				comp.y = 1000;
		}
	}

}

void OscillatePositionSystem::LateUpdate(std::shared_ptr<ComponentManager> cMan)
{
}