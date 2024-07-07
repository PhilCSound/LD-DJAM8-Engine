#pragma once
#include "entity.hpp"

Entity::Entity(unsigned int id, std::shared_ptr<ComponentManager> cMan)
{
	m_id = id;
	m_compManager = cMan;
}

const unsigned int Entity::Get_ID() const
{
	return m_id;
}