#pragma once
#include "componentcontainer.hpp"
#include <string>
#include "entity.hpp"

class MemoryPool
{
public:
	//Copy/Move/= constructors deleted
	MemoryPool(const MemoryPool& copy) = delete;
	MemoryPool(MemoryPool&& move) = delete;
	void operator=(const MemoryPool&) = delete;
	
	//Public Static Functions
	static MemoryPool* GetInstance();

	//Public Member Functions
	Entity CreateEntity(const std::string& tag = "");

private:
	//Constructor
	MemoryPool();

	//Private Static Variables
	static MemoryPool* MEMORY_POOL;
	
	//Private Variables
	const unsigned int MAX_NUM_ENTITYS = 1000;
	std::vector<std::string> m_tags;
	std::vector<bool> m_entityActive;
	ComponentContainer m_componetContainer;

};