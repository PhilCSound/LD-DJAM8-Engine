#pragma once
#include "componentmanager.hpp"
#include <memory>
#include <cassert>

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

		template<typename T>
		T& GetComponent()
		{
			auto compPair = m_compManager->GetComponentPair<T>(m_id);
			assert(compPair.first && "ENTITY DOES NOT HAVE COMPONENT");
			return compPair.second;
		}

	private:
		//Allowing only the ComponentManager to construct Entitys
		friend class Engine;

		//Constructor
		Entity(unsigned int id, std::shared_ptr<ComponentManager> cMan);
		Entity() = delete;

		//Member Variables
		unsigned int m_id;
		std::shared_ptr<ComponentManager> m_compManager;
};