#pragma once
#include "isystem.hpp"
#include "components/cposition.hpp"

class OscillatePositionSystem : public ISystem
{

public:
	void Initialize(std::shared_ptr<ComponentManager>) override;
	void PreUpdate(std::shared_ptr<ComponentManager>) override;
	void Update(std::shared_ptr<ComponentManager>) override;
	void LateUpdate(std::shared_ptr<ComponentManager>) override;
	void Render(sf::RenderTarget& targ, std::shared_ptr<Engine> eng) override;


private:

};