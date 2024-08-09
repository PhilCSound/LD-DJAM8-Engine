#include "inputmap.hpp"

InputMap::InputMap(const std::string& mapName, const std::string& whatConName)
	: m_mapName(mapName), m_whatControlledName(whatConName)
{
}

const std::string& InputMap::GetMapName() const
{
	return m_mapName;
}

const std::string& InputMap::GetWhatControlledName() const
{
	return m_whatControlledName;
}

const ActionEnum InputMap::PollEvent(sf::Event& ev) 
{
	switch (ev.type)
	{
	case sf::Event::MouseButtonPressed:
		if (m_mouseButtonMap.contains(ev.mouseButton.button))
			return m_mouseButtonMap[ev.mouseButton.button];
		break;

	case sf::Event::MouseButtonReleased:
		if (m_mouseButtonMap.contains(ev.mouseButton.button))
			return m_mouseButtonMap[ev.mouseButton.button];
		break;
	
	case sf::Event::KeyPressed:
		auto key = sf::Keyboard::localize(ev.key.scancode);
		if (m_keyboardInputMap.contains(key))
			return m_keyboardInputMap[key];
		break;
	
	case sf::Event::KeyReleased:
		auto key = sf::Keyboard::localize(ev.key.scancode);
		if (m_keyboardInputMap.contains(key))
			return m_keyboardInputMap[key];
		break;
	
	default:
		break;
	}
	return ActionEnum::Nothing;
}
