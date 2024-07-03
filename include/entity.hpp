#pragma once

class Entity
{
	public:
		Entity(unsigned int id);
		const unsigned int Get_ID() const;
	private:
		unsigned int m_id;
};