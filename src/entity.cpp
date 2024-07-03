#pragma once
#include "entity.hpp"

Entity::Entity(unsigned int id)
{
	m_id = id;
}

const unsigned int Entity::Get_ID() const
{
	return m_id;
}