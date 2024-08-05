#pragma once
#include "isystem.hpp"
#include "components/cposition.hpp"

class OscillatePositionSystem : public ISystem
{

public:
	void Initialize(Engine* eng) override;
	void PreUpdate(Engine* eng) override;
	void Update(Engine* eng) override;
	void LateUpdate(Engine* eng) override;
	void Render(sf::RenderTarget& targ, Engine* eng) override;


private:

};