#pragma once
#include "iscene.hpp"

class TestScene : public IScene
{
public:
	TestScene() = default;

	void Initialize(Engine* eng) override;
	void OnSceneDestroy(Engine* eng) override;
	void Update(Engine* eng) override;

private:
	std::vector<Entity> m_entities{};

};