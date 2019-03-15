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
	if (this != nullptr)
	{
		delete[] events_;
	}
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
	auto *buff = new char[100];

	x.add_new_event();
	in.getline(buff, 100);
	read_line(buff, x);
	delete[] buff;
	return (in);
}
void read_line(char* buff, Concert& x)
{
	auto i = 0, j = 0, capacity = 0, tickets = 0;
	auto *name = new char[50];
	auto *date = new char[20];
	char tickets_char[10], capacity_char[10];
	while (buff[i] != ';')
	{
		name[i] = buff[i];
		i++;
	}
	name[i] = '\0';
	i++;
	while (buff[i] != ';')
	{
		capacity_char[j] = buff[i];
		j++;
		i++;
	}
	capacity = strtol(capacity_char, nullptr, 10);
	j = 0;
	i++;
	while (buff[i] != ';')
	{
		tickets_char[j] = buff[i];
		j++;
		i++;
	}
	tickets = strtol(tickets_char, nullptr, 10);
	j = 0;
	i++;
	while (i < static_cast<int>(strlen(buff)))
	{
		date[j] = buff[i];
		j++;
		i++;
	}
	date[j] = '\0';
	x.set_event(name, capacity, tickets, date);
	delete[] name;
	delete[] date;
}
