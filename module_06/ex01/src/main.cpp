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

	uintptr_t raw = Serializer::serialize(data);
	Data *data2 = Serializer::deserialize(raw);

	std::cout << BOLD_WHITE << "data2->name: " << data2->name << RESET << std::endl;
	std::cout << BOLD_WHITE << "data2->age: " << data2->age << RESET << std::endl;
	std::cout << BOLD_WHITE << "data2->next->name: " << data2->next->name << RESET << std::endl;
	std::cout << BOLD_WHITE << "data2->next->age: " << data2->next->age << RESET << std::endl;

	delete data->next;
	delete data;
	return 0;
}