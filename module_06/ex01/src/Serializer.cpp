#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

// constructor
Serializer::Serializer() {
	std::cout << BOLD_GREEN << "constructor Serializer created" << RESET << std::endl;
}

// copy constructor
Serializer::Serializer(const Serializer &copy) {
	std::cout << BOLD_GREEN << "copy constructor Serializer created" << RESET << std::endl;
	*this = copy;
}

// destructor
Serializer::~Serializer() {
	std::cout << BOLD_RED << "destructor Serializer destroyed" << RESET << std::endl;
}

// assignation operator
Serializer &Serializer::operator=(const Serializer &copy) {
	std::cout << BOLD_GREEN << "assignation operator Serializer created" << RESET << std::endl;
	if (this not_eq &copy) {
	}
	return *this;
}