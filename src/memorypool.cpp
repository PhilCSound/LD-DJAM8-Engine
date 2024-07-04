#pragma once
#include "memorypool.hpp"

MemoryPool* MemoryPool::MEMORY_POOL = nullptr;

MemoryPool::MemoryPool()
	: m_tags{}, m_entityActive{}, m_componetContainer{}
{
	m_tags.resize(MAX_NUM_ENTITYS);
	m_entityActive.resize(MAX_NUM_ENTITYS);

	//BOILERPLATE DO THIS FOR EVERY COMPONENT IN COMPONENT CONTAINER
	std::get<std::vector<std::string>>(m_componetContainer).resize(MAX_NUM_ENTITYS);
}

MemoryPool* MemoryPool::GetInstance()
{
	if (MEMORY_POOL == nullptr)
		MEMORY_POOL = new MemoryPool();
	return MEMORY_POOL;
}

Entity MemoryPool::CreateEntity(const std::string& tag)
{
	for (auto i = 0U; i < m_entityActive.size(); i++)
	{
		if (m_entityActive.at(i) == false)
		{
			m_entityActive.at(i) = true;
			m_tags.at(i) = tag;
			return Entity(i);
		}
	}
	//IF OUR ENTITY LIST IS FULL WE "GRACEFULLY" ABORT.
	//TODO: DETERMINE THIS.asd
	return Entity(0);
}
