#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", target, 145, 137) {
    std::cout << BOLD_GREEN "constructor ShrubberyCreationForm " << this->name << " created" RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy)
{
    std::cout << BOLD_GREEN "constructor copy ShrubberyCreationForm " << this->name << " created" RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << BOLD_GREEN "assignation operator ShrubberyCreationForm " << this->name << " created" RESET << std::endl;
	if (this not_eq &copy)
		this->target = copy.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BOLD_RED "destructor ShrubberyCreationForm " << this->name << " destroyed" RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::ofstream file((this->getTarget() + "_shrubbery").c_str());
    if (!file) {
        std::cout << "Error: could not create file" << std::endl;
        return;
    }
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣦⣼⠻⠿⣦⣄⠀⢀⣼⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡾⠃⠀⠀⠀⠉⠙⠚⠙⢿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡾⣦⢾⣦⣤⠀⠀⢀⢙⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⡀⢀⣼⠿⣷⣼⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡴⠾⠋⠀⠀⠀⠉⣻⡿⠞⠛⢻⣅⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠙⡿⠛⠁⠀⠉⠁⠛⣿⣾⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢿⡄⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⣹⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡶⣿⡉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⢰⣦⣶⣶⣤⣀⠀⠀⠀⠀⢹⣷⣶⣦⣤⡶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣦⠀⢹⣧⣦⣴⠆⢠⣦⣦⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⢀⣠⣶⡾⠃⠀⠀⠉⠟⠷⢶⣶⣶⡀⠀⣀⣤⣸⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣀⣤⣠⣤⡶⣿⣳⠟⠁⣤⣾⠀⠀⠘⠷⠋⠀⣸⣇⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⢰⣿⠟⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠷⡼⠏⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠛⠀⠈⠘⠃⠉⠀⠀⠈⠛⠒⠋⠀⠀⠀⠀⠀⠀⠀⠈⠉⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⣰⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡄⢀⣴⡇⠀⢀⣠⣾⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⡇⢀⣀⡀⠀⠀⠀⠀⠀⠀\n"
		 << "⠋⣿⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⠀⠀⠀⢿⡽⣿⠿⣧⠷⣼⣧⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠋⢯⡆⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⣾⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠋⠱⣿⣿⢶⠀⠀⢣⣿⡆⠈⡷⢷⡜⣷⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠇⠀⠀⠀⠀⠀⠀\n"
		 << "⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣓⣾⠽⣇⠀⢁⡞⠑⠛⢻⡾⣷⣀⡄⣀⣤⣠⠄⠀⣠⣤⠀⠀⠀⠀⠀⠀⣀⡀⣤⣠⣤⡼⣉⣤⣦⡀⢀⠀⠀⠀\n"
		 << "⠈⠙⣿⣄⠀⣠⣦⡄⠀⠀⢰⣶⣆⠀⠀⡀⠀⠀⠀⠀⢠⣀⣴⠋⠉⠹⣆⢹⣄⠸⠀⢠⠟⢸⠃⠈⠉⢻⡏⢻⠁⠀⢠⣟⣞⣀⠀⠀⢀⠀⠀⠿⢽⣧⣹⣠⣿⠏⠉⠙⠛⢻⣖⠴⣦\n"
		 << "⠀⠀⠛⠿⠺⠻⠻⣧⣶⣴⣾⡿⣿⣴⠟⢛⡷⠂⠀⠀⡀⠀⠁⠀⠀⠀⠈⠛⣛⠓⣆⣞⠀⡏⠀⠀⠀⣸⠃⡏⢀⡠⠼⡟⢫⣧⡖⠊⠉⠀⠀⠀⠀⠀⠉⠙⠁⠀⠀⠀⠀⠀⠀⠀⣿\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠈⠛⢻⣿⣤⣀⠀⢠⡾⠁⠀⠀⠳⣽⠂⢀⠀⣀⡴⣶⣶⠉⢷⠈⠙⠀⣇⠀⠀⣰⢃⡼⠛⠉⣠⡤⠿⠻⣆⠙⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⢀⣀⣠⡏⠉⠻⡷⡞⠀⠀⠀⣠⠞⣠⠴⠞⠋⠁⠀⠈⢿⣇⡤⡶⠛⣷⣭⠀⠀⠀⠀⠁⣻⣋⣀⣀⣀⢀⣈⠳⠸⠷⠤⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸\n"
		 << "⠀⠀⠀⠀⢠⣾⣟⠟⠛⠋⠀⠀⠀⠀⠀⠀⠀⠠⢃⣰⠃⠀⠀⠀⠀⠀⠀⠈⠟⠀⠀⠀⢱⢿⡀⠠⡤⢤⣼⠟⠋⠛⠉⠋⠁⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠻\n"
		 << "⠀⠀⠀⠀⠈⣿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠇⣼⠁⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣄⣰⡞⠻⠃⠀\n"
		 << "⠀⠀⠀⠀⠀⢻⣧⣤⣀⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣴⠾⠋⠀⠃⠠⡇⠀⠀⣀⡀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣛⣋⡁⠉⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠉⠙⠉⣿⢂⣄⠀⠀⠀⠀⠀⣿⢀⡀⠀⠀⠀⠀⠀⢴⣤⠶⠷⠛⠉⢳⠀⠀⠀⠀⣰⠿⣤⢦⠟⢻⢻⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠻⣻⠟⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣦⣴⣤⡿⢿⣋⣿⠇⠀⠀⠀⠀⠀⠈⠙⠲⡄⠀⠀⢸⠀⠀⠀⣰⠃⠀⠉⠉⠀⣾⡛⠁⠀⠀⠀⠀⠀⠀⠀⠀⣰⢦⣦⣤⣤⣴⡏⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠉⠀⠁⠀⠈⣯⡀⡀⡀⢀⠀⣠⡄⣼⠶⠾⠃⠀⠀⡞⠀⠀⠀⢹⠀⠀⠀⠀⠀⠈⢷⢦⣤⣄⠀⠀⠀⢠⣤⣴⠟⠀⠀⠉⠀⠈⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠓⠛⠛⠛⠋⠛⠋⠀⠀⠀⠀⠀⡇⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠈⠀⠹⠷⣾⡍⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⠀⠀⠸⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡇⠀⠀⠀⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
		 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠏⠀⠀⠀⠀⢈⡻⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    file.close();
}