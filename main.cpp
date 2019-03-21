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
	con.sort_by_name();
	std::cout << con;
	system("pause");
	return(0);
}
