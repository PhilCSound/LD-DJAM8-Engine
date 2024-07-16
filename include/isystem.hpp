#pragma once
#include "componentmanager.hpp"

class ISystem
{
public:
	ISystem(bool multiThreadSafe = false);

	virtual void Initialize(std::shared_ptr<ComponentManager> cMan) = 0;
	virtual void PreUpdate(std::shared_ptr<ComponentManager> cMan) = 0;
	virtual void Update(std::shared_ptr<ComponentManager> cMan) = 0;
	virtual void LateUpdate(std::shared_ptr<ComponentManager> cMan) = 0;
	
	const bool IsMultiThreadSafe() const;
	void SetMultiThreadSafety(bool isSafe);

protected:
	bool m_multiThreadSafe = false;
	
};