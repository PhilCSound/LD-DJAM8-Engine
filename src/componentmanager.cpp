#pragma once
#include "componentmanager.hpp"

ComponentManager::ComponentManager(std::size_t maxEntities, std::size_t maxCompTypes)
	: m_tags{}, m_entityActive{}, m_maxNumEntities{ maxEntities }, 
		m_maxNumComponents{maxCompTypes}
{
	m_tags.resize(m_maxNumEntities);
	m_entityActive.resize(m_maxNumEntities);
}

unsigned int ComponentManager::CreateEntityID(const std::string& tag)
{
	for (auto i = 0U; i < m_entityActive.size(); i++)
	{
		if (m_entityActive.at(i) == false)
		{
			m_entityActive.at(i) = true;
			m_tags.at(i) = tag;
			return i;
		}
	}
	//TODO: DETERMINE HOW TO ERROR HANDLE THIS SCENARIO
	return 9999;
}
