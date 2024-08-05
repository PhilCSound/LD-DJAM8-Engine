#pragma once
#include <unordered_map>
#include <string>
#include "isystem.hpp"

class ISystem;

class SystemManager
{
public:
	SystemManager(std::size_t maxSystems = 32U);

	void ClearAllSystems();
	ISystem* GetSystem(const std::string& systemName);
	std::size_t GetNumberOfRegSystems();
	bool RegisterSystem(const std::string& systemName, ISystem* systemToAdd);
	void RunSystems(Engine* eng);
	void UnRegisterSystem(const std::string& systemName);

private:
	std::unordered_map<std::string, ISystem*> m_systemMap {};
	std::size_t m_maxNumOfSystems;
};