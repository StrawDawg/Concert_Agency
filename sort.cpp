#include "concerts.h"

int comp_concerts_name(const void * obj1, const void * obj2)
{
	auto *event1 = ((Event*)obj1), *event2 = ((Event*)obj2);

	return (_stricmp((*event1).name, (*event2).name));
}

int comp_concerts_date(const void * obj1, const void * obj2)
{
	auto *event1 = ((Event*)obj1), *event2 = ((Event*)obj2);

	return (_stricmp((*event1).date, (*event2).date));
}

int comp_concerts(const void * obj1, const void * obj2)
{
	auto *event1 = ((Event*)obj1), *event2 = ((Event*)obj2);

	if (_stricmp((*event1).date, (*event2).date) != 0)
	{
		return ((_stricmp((*event1).date, (*event2).date)));
	}
	else
	{
		return (_stricmp((*event1).name, (*event2).name));
	}
}