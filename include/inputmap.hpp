#pragma once
#include <unordered_map>
#include "SFML/Graphics.hpp"
#include "actionenum.hpp"

class InputMap
{

public:
	InputMap(const std::string& mapName = "", const std::string& contName = "");
	const std::string& GetMapName() const;
	const std::string& GetWhatControlledName() const;
	const ActionEnum PollEvent(sf::Event& ev);
	void InsertKeyAction(sf::Keyboard::Key key, ActionEnum action);
	void InsertMouseAction(sf::Mouse::Button button, ActionEnum action);

private:
	std::string m_mapName{};
	std::string m_whatControlledName {};
	std::unordered_map<sf::Keyboard::Key, ActionEnum> m_keyboardInputMap{};
	std::unordered_map<sf::Mouse::Button, ActionEnum> m_mouseButtonMap{};
};