#pragma once
#include <vector>
#include <utility>
#include <cassert>

class IComponentArray
{
public:
	virtual ~IComponentArray() = default;
};

template <typename ComponentType>
class ComponentArray : public IComponentArray
{

public:
	ComponentArray() = delete;
	ComponentArray(std::size_t maxNumEntitys) { m_compArray.resize(maxNumEntitys); }
	std::size_t Size() { return m_compArray.size(); }
	bool ContainsComponent(const std::size_t& index) { return m_compArray.at(index).first; }
	ComponentType& GetComponent(const std::size_t& index) { return m_compArray.at(index).second; }
	
	std::pair<bool, ComponentType>& operator[](std::size_t index)
	{
		// Ensure the index is within bounds
		assert(index < m_compArray.size() && "Index out of bounds.");
		return m_compArray[index];
	}

private:
	std::vector<std::pair<bool, ComponentType>> m_compArray;

};