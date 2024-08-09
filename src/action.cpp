#include "action.hpp"

Action::Action(ActionEnum action, const std::string& targ, bool stopAction)
	: m_actionType(action), m_targetTag(targ), m_stopAction(stopAction)
{
}

const ActionEnum Action::GetActionEnum() const
{
	return m_actionType;
}

const bool Action::IsActionStopped() const
{
	return m_stopAction;
}

const std::string& Action::GetTargetTag() const
{
	return m_targetTag;
}
