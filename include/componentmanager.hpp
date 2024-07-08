#pragma once
#include "componentcontainer.hpp"
#include <string>
#include <map>
#include <set>
#include <memory>
#include <cassert>

class ComponentManager
{
public:
	//Constructor
	ComponentManager(std::size_t maxEntities = 1000, std::size_t maxCompTypes = 24);
	//Copy/Move/= constructors deleted
	ComponentManager(const ComponentManager& copy) = delete;
	ComponentManager(ComponentManager&& move) = delete;
	void operator=(const ComponentManager&) = delete;

	//Public Member Functions
	unsigned int CreateEntityID(const std::string& tag = "");
	
	template<typename T>
	void RegisterComponent()
	{
		std::size_t id = typeid(T).hash_code();
		std::size_t index = m_componentArrays.size();
		assert(!m_typeSet.contains(id) && "Error, component type has already been registered.");
		m_typeIndexMap[id] = index;
		m_componentArrays.push_back(std::make_shared<ComponentArray<T>>(m_maxNumEntities));
		m_typeSet.insert(id);
	}

	template<typename T>
	std::shared_ptr<ComponentArray<T>> GetComponentArray()
	{
		std::size_t id = typeid(T).hash_code();
		assert(m_typeSet.contains(id) && "Error, component type has not been registered.");
		std::size_t index = m_typeIndexMap[id];
		return std::static_pointer_cast<ComponentArray<T>>(m_componentArrays[index]);
	}

	template<typename T>
	std::pair<bool, T>& GetComponentPair(unsigned int index)
	{
		auto compArray = GetComponentArray<T>();
		return (*compArray)[index];
	}

	template<typename T>
	void AddComponent(const T& val, unsigned int index)
	{
		std::shared_ptr<ComponentArray<T>> ptr = GetComponentArray<T>();
		auto& pair = (*ptr)[index];
		pair.first = true;
		pair.second = val;
	}

	template<typename T>
	void RemoveComponent(unsigned int index)
	{
		std::shared_ptr<ComponentArray<T>> ptr = GetComponentArray<T>();
		auto& pair = (*ptr)[index];
		pair.first = false;
	}

private:
	//Private Variables
	std::size_t m_maxNumEntities;
	std::size_t m_maxNumComponents;

	std::vector<std::string> m_tags;
	std::vector<bool> m_entityActive;
	std::vector<std::shared_ptr<IComponentArray>> m_componentArrays;
	std::map<std::size_t, std::size_t> m_typeIndexMap;
	std::set<std::size_t> m_typeSet; //Removes possibility of having two of the same component
};
