#pragma once
#include <iostream>
#include <fstream>
#include <immintrin.h>
#include <string>
#include <vector>

struct Event
{
	std::string name;
	int capacity, tickets_left;
	std::string date;
};
class Concert
{
	std::vector<Event> events_;
	int amount_;

public:
	Concert() = default;
	Concert(Concert const&) = delete;
	Concert(Concert&&) = delete;
	void book_ticket(int i) const;
	int quantity_of_concerts() const;
	void sort_by_name();
	void sort_by_date();
	Event operator[] (int i) const;
	std::vector<Event>::iterator begin();
	std::vector<Event>::iterator end();
	friend std::ostream& operator<<(std::ostream& out, const Concert& x);
	friend  std::istream& operator>>(std::istream& in, Concert& x);
};