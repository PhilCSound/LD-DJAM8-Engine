#pragma once
#include "systemmanager.hpp"

SystemManager::SystemManager(std::size_t maxSystems)
	: m_maxNumOfSystems(maxSystems)
{
}

void SystemManager::ClearAllSystems()
{
	m_systemMap.clear();
}

ISystem* SystemManager::GetSystem(const std::string& systemName)
{
	assert(m_systemMap.contains(systemName) && "Error, system not registered.");
	return m_systemMap[systemName];
}

std::size_t SystemManager::GetNumberOfRegSystems()
{
	return m_systemMap.size();
}

bool SystemManager::RegisterSystem(const std::string& systemName, ISystem* systemToAdd)
{
	if (GetNumberOfRegSystems() >= m_maxNumOfSystems)
		return false;
	
	m_systemMap.insert( {systemName, systemToAdd} );
	return true;
}

void SystemManager::RunSystems(Engine* eng)
{
	//PreUpdate
	for (auto& i : m_systemMap)
		i.second->PreUpdate(eng);
	//Update
	for (auto& i : m_systemMap)
		i.second->Update(eng);
	//PreUpdate
	for (auto& i : m_systemMap)
		i.second->LateUpdate(eng);
	
}

void SystemManager::UnRegisterSystem(const std::string& systemName)
{
	m_systemMap.erase(systemName);
}