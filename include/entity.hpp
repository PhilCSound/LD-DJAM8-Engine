#pragma once
#include "componentmanager.hpp"

class ComponentManager;

class Entity
{
	public:
		Entity(unsigned int id);
		const unsigned int Get_ID() const;

		template<typename T>
		void AddComponent(const T& typeToAdd)
		{
			auto memPool = ComponentManager::GetInstance();
			memPool->AddComponent<T>(typeToAdd, m_id);
		}

		template<typename T>
		void RemoveComponent()
		{
			auto memPool = ComponentManager::GetInstance();
			memPool->RemoveComponent<T>(m_id);
		}

	private:
		unsigned int m_id;
};