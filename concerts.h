#pragma once
#include <iostream>
#include <fstream>
#include <immintrin.h>
#include <string>

struct Event
{
	char *name;
	int capacity;
	int tickets_left;
	char *date;

	Event();
	Event& operator=(Event const& x);
	virtual ~Event();
};
class Concert
{
	Event* events_;
	int amount_;

	friend std::ostream& operator<<(std::ostream& out, const Concert& x);
	friend  std::istream& operator>>(std::istream& in, Concert& x);
	friend void read_line(char* buff, Concert& x);

public:
	Concert();
	Concert(Concert const& ptr);
	Concert(Concert&& ptr) noexcept;
	void add_new_event();
	void set_event(char name[], int capacity, int tickets, char date[]) const;
	void book_ticket(int i) const;
	int quantity_of_concerts() const;
	Event* events() const;
	Event operator[] (int i) const;
	virtual ~Concert();
};
int comp_concerts_name(const void * obj1, const void * obj2);
int comp_concerts_date(const void * obj1, const void * obj2);
int comp_concerts(const void * obj1, const void * obj2);