#pragma once

//Test Component, used by the oscillate position system 
// for testing system/component functionallity.

struct CPosition
{
	CPosition(int _x = 0, int _y = 0)
		: x(_x), y(_y)
	{

	}

	int x = 0;
	int y = 0;
};