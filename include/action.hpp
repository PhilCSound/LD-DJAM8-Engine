#pragma once
#include "actionenum.hpp"
#include <string>

class Action
{
public:
	Action(ActionEnum action, const std::string& targ, bool stopAction = false);
	const ActionEnum GetActionEnum() const;
	const bool IsActionStopped() const;
	const std::string& GetTargetTag() const;

private:
	ActionEnum m_actionType;
	bool m_stopAction = false;
	std::string m_targetTag;
};