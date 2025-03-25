#include "Serializer.hpp"

int	main()
{
	Data *data = new Data;
	data->name = "John";
	data->age = 42;
	data->next = new Data;
	data->next->name = "Doe";
	data->next->age = 24;
	data->next->next = NULL;

	std::cout << BOLD_WHITE << "data->name: " << data->name << RESET << std::endl;
	std::cout << BOLD_WHITE << "data->age: " << data->age << RESET << std::endl;
	std::cout << BOLD_WHITE << "data->next->name: " << data->next->name << RESET << std::endl;
	std::cout << BOLD_WHITE << "data->next->age: " << data->next->age << RESET << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << BOLD_WHITE << "before serialize : data= " << data << RESET << std::endl;
	uintptr_t raw = Serializer::serialize(data);
	std::cout << BOLD_WHITE << "after serialize : raw= " << raw << RESET << std::endl;
	Data *data2 = Serializer::deserialize(raw);
	std::cout << BOLD_WHITE << "after deserialize : data2= " << data2 << RESET << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << BOLD_WHITE << "data2->name: " << data2->name << RESET << std::endl;
	std::cout << BOLD_WHITE << "data2->age: " << data2->age << RESET << std::endl;
	std::cout << BOLD_WHITE << "data2->next->name: " << data2->next->name << RESET << std::endl;
	std::cout << BOLD_WHITE << "data2->next->age: " << data2->next->age << RESET << std::endl;

	std::cout << std::endl << std::endl;
	if (data->name == data2->name && data->age == data2->age && data->next->name == data2->next->name && data->next->age == data2->next->age)
		std::cout << BOLD_GREEN << "Data is the same" << RESET << std::endl;
	else
		std::cout << BOLD_RED << "Data is different" << RESET << std::endl;

	delete data->next;
	delete data;
	return 0;
}