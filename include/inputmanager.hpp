#pragma once
#include <string>
#include <unordered_map>
#include <set>
#include "action.hpp"
#include "inputmap.hpp"
#include "actionmanager.hpp"

class InputManager
{
public:
	InputManager() = default;
	void SetActiveInputConfiguration(const std::string& inputConfig);
	void ProcessEvents(sf::Event& ev, ActionManager& actionMan);
	void UnactivateAllInputConfigurations();

private:
	std::unordered_map<std::string, InputMap> m_inputConfigurations{};
	std::set<std::string> m_activeInputConfigurations{};

	//STRINGSS
	//input -> command -> posts command
	//input -> controller reads input -> tells command system whats happnen -> sets the appropriate data in componnent.
};