#include "concerts.h"
#include <string>

int main()
{
	Concert con;
	std::ifstream text("Concerts.txt");

	if(!text.is_open())
	{
		std::cout << "This file cannot be opened";
	}
	else
	{
		while(text.good())
		{
			text >> con;
		}
	}
	text.close();

	std::cout << "Enter new concert:\n";
	std::cin >> con;
	std::cout << con;
	con.book_ticket(3);
	qsort(con.events(), con.quantity_of_concerts(), sizeof(Event), comp_concerts);
	std::cout << con;
	system("pause");
	return(0);
}
