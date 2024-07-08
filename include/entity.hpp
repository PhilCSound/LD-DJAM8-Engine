#pragma once
#include "componentmanager.hpp"
#include <memory>
#include <cassert>

class Entity
{
public:
	//Public Functions
	const unsigned int Get_ID() const;

	//Templated Functions
	template<typename T>
	void AddComponent(const T& typeToAdd);

	template<typename T>
	void RemoveComponent();

	template<typename T>
	T& GetComponent();

private:
	//Allowing only the Engine to construct Entitys
	friend class Engine;

	//Constructor
	Entity(unsigned int id, std::shared_ptr<ComponentManager> cMan);
	Entity() = delete;

	//Member Variables
	unsigned int m_id;
	std::shared_ptr<ComponentManager> m_compManager;
};



//---------------------------------
//	Templated function definitions
//---------------------------------

template<typename T>
void Entity::AddComponent(const T& typeToAdd)
{
	m_compManager->AddComponent<T>(typeToAdd, m_id);
}

template<typename T>
void Entity::RemoveComponent()
{
	m_compManager->RemoveComponent<T>(m_id);
}

template<typename T>
T& Entity::GetComponent()
{
	auto compPair = m_compManager->GetComponentPair<T>(m_id);
	assert(compPair.first && "ENTITY DOES NOT HAVE COMPONENT");
	return compPair.second;
}