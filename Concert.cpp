#include "concerts.h"

Concert::Concert()
{
	amount_ = 0;
	events_ = new Event[amount_ + 1];
}

Concert::Concert(Concert const& ptr)
{
	amount_ = ptr.amount_;
	events_ = new Event[amount_];
	for (auto i = 0; i < amount_; i++)
	{
		events_[i] = ptr.events_[i];
	}
}

Concert::Concert(Concert&& ptr) noexcept
{
	amount_ = ptr.amount_;
	events_ = ptr.events_;
	ptr.events_ = nullptr;
}

void Concert::add_new_event()
{
	if (amount_ == 0)
	{
		amount_++;
	}
	else
	{
		auto* temp = new Event[++amount_];
		for (auto i = 0; i < amount_ - 1; i++)
		{
			temp[i] = events_[i];
		}
		delete[] events_;
		events_ = new Event[amount_];
		for (auto i = 0; i < amount_; i++)
		{
			events_[i] = temp[i];

		}
		delete[] temp;
	}
}

void Concert::set_event(char name[], int capacity, int tickets, char date[]) const
{
	auto  const i = amount_ - 1;
	events_[i].name = _strdup(name);
	events_[i].capacity = capacity;
	events_[i].tickets_left = tickets;
	events_[i].date = _strdup(date);

}

void Concert::book_ticket(int i) const
{
	if(i > amount_)
	{
		throw std::exception("Wrong index");
	}
	else
	{
		if (events_[i - 1].tickets_left != 0)
		{
			events_[i - 1].tickets_left--;
		}
		else
		{
			throw std::exception("There are no tickets left:(");
		}
	}
}

int Concert::quantity_of_concerts() const
{
	return(amount_);
}

Event* Concert::events() const
{
	return(events_);
}

Event Concert::operator[] (int i) const
{
	return(this->events_[i]);
}

Concert::~Concert()
{
	delete[] events_;
}

std::ostream& operator<<(std::ostream& out, const Concert& x)
{
	out << "\nConcerts:\n";
	for (auto i = 0; i < x.amount_; i++)
	{
		out << i + 1 << ") \"" << x.events_[i].name << "\" " << x.events_[i].capacity
			<< " " << x.events_[i].tickets_left << " " << x.events_[i].date << std::endl;
	}
	return (out);
}

std::istream& operator>>(std::istream& in, Concert& x)
{
	char buff[100];
	char* ptr = nullptr;
	auto capacity = 0, tickets = 0;
	auto *name = new char[50];
	auto *date = new char[20];

	x.add_new_event();
	in.getline(buff, 100);
	strcpy_s(name, 50, strtok_s(buff, ";", &ptr));
	capacity = strtol(strtok_s(nullptr, ";", &ptr), nullptr, 10);
	tickets = strtol(strtok_s(nullptr, ";", &ptr), nullptr, 10);
	strcpy_s(date, 20, strtok_s(nullptr, "\n", &ptr));
	x.set_event(name, capacity, tickets, date);
	delete[] name;
	delete[] date;
	return (in);
}