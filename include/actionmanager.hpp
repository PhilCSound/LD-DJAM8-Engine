#pragma once
#include <queue>
#include <string>
#include "action.hpp"

class ActionManager
{
public:
	ActionManager() = default;
	void PostAction(Action action);
	const bool IsEmpty() const;
	Action& GetNextAction();
	void ClearActionList();

private:
	std::queue<Action> m_action{};
};