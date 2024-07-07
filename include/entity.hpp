#pragma once
#include "componentmanager.hpp"
#include <memory>

class Entity
{
	public:
		const unsigned int Get_ID() const;

		template<typename T>
		void AddComponent(const T& typeToAdd)
		{
			m_compManager->AddComponent<T>(typeToAdd, m_id);
		}

		template<typename T>
		void RemoveComponent()
		{
			m_compManager->RemoveComponent<T>(m_id);
		}

	private:
		//Allowing only the ComponentManager to construct Entitys
		friend class ComponentManager;

		//Constructor
		Entity(unsigned int id, std::shared_ptr<ComponentManager> cMan);
		Entity() = delete;

		//Member Variables
		unsigned int m_id;
		std::shared_ptr<ComponentManager> m_compManager;
};