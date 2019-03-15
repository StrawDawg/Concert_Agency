#include "concerts.h"

Event::Event()
{
	name = new char[50];
	capacity = 0;
	tickets_left = 0;
	date = new char[20];
}

Event& Event::operator=(Event const& x)
{
	if (this != &x)
	{
		name = _strdup(x.name);
		capacity = x.capacity;
		tickets_left = x.tickets_left;
		date = _strdup(x.date);
	}
	return *this;
}

Event::~Event()
{
	delete[] name;
	delete[] date;
}