#include "actionmanager.hpp"

void ActionManager::PostAction(Action action)
{
	m_action.push(action);
}

const bool ActionManager::IsEmpty() const
{
	return m_action.empty();
}
Action& ActionManager::GetNextAction()
{
	auto& act = m_action.front();
	m_action.pop();
	return act;
}

void ActionManager::ClearActionList()
{
	m_action = std::queue<Action>{};
}