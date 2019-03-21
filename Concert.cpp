#include "concerts.h"
#include  <algorithm>
#include <iomanip>

int Concert::quantity_of_concerts() const
{
	return(amount_);
}

Event Concert::operator[] (int i) const
{
	return(this->events_[i]);
}

void Concert::sort_by_name()
{
	std::sort(events_.begin(), events_.end(), [](const Event e1, const Event e2) -> bool
	{
		return e1.name < e2.name;
	});
}

std::vector<Event>::iterator Concert::begin()
{
	return events_.begin();
}

std::vector<Event>::iterator Concert::end()
{
	return events_.end();
}

std::ostream& operator<<(std::ostream& out, Concert const& x)
{
	auto i = 1;
	out << "\nConcerts:\n";
	for (const auto& e : x.events_)
	{
		out << i << ") \"" << e.name << "\" " << e.capacity << " " << e.tickets_left << " " << e.date << "\n";
		i++;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Concert& x)
{
	std::string line;
	std::getline(in, line);

	size_t pos = 0;
	std::string parts[4];

	for (auto& part : parts)
	{
		pos = line.find(';');
		part = line.substr(0, pos);
		line.erase(0, pos + 1);
	}

	Event e;
	e.name = parts[0];
	e.capacity = std::stoi(parts[1]);
	e.tickets_left = std::stoi(parts[2]);
	e.date = parts[3];

	x.events_.push_back(e);

	return in;
}