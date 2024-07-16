#pragma once
#include "isystem.hpp"

ISystem::ISystem(bool multiThreadSafe)
	: m_multiThreadSafe(multiThreadSafe)
{
}

const bool ISystem::IsMultiThreadSafe() const
{
	return m_multiThreadSafe;
}

void ISystem::SetMultiThreadSafety(bool isSafe)
{
	m_multiThreadSafe = isSafe;
}
