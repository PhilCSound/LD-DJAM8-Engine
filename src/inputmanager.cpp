#include "inputmanager.hpp"

void InputManager::SetActiveInputConfiguration(const std::string& inputConfig)
{
	m_activeInputConfigurations.insert(inputConfig);
}

void InputManager::ProcessEvents(sf::Event& ev, ActionManager& actionMan)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		for (auto& i : m_activeInputConfigurations)
		{
			ActionEnum result = m_inputConfigurations[i].PollEvent(ev);
			auto& target = m_inputConfigurations[i].GetWhatControlledName();
			if (result != ActionEnum::Nothing)
				actionMan.PostAction(Action{ result, target });
		}
		break;
	
	case sf::Event::KeyReleased:
		for (auto& i : m_activeInputConfigurations)
		{
			ActionEnum result = m_inputConfigurations[i].PollEvent(ev);
			auto& target = m_inputConfigurations[i].GetWhatControlledName();
			if (result != ActionEnum::Nothing)
				actionMan.PostAction(Action{ result, target, true});
		}
		break;

	default:
		break;
	}
}

void InputManager::UnactivateAllInputConfigurations()
{
	m_activeInputConfigurations.clear();
}