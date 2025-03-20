COMP = c++
CFLAG = -Wall -Werror -Wextra -g3 -std=c++98

NAME = Bureaucrat

SRC =	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp


OBJ = $(SRC:.cpp=.o)

all: clear_terminal $(NAME)
	@echo "\033[1;32m💥 Compilation terminée ! 💥\033[0m"
	@echo "\033[1;33m🔨 Projet prêt ! 🎉\033[0m"
	@echo "\033[1;33m🔨 Lancer avec ./$(NAME) 🎉\033[0m"
	@echo "\033[1;33m✨ N'hésite pas à donner un outstanding project ! 🎉\033[0m"

clear_terminal:
	@clear

$(NAME): $(OBJ)
	@echo "\033[1;33m🔧 Liaison...\033[0m"
	@$(COMP) $(CFLAG) $(OBJ) -o $(NAME)
	@echo "\033[1;32m🚀 $(NAME) généré !\033[0m"

%.o: %.cpp
	@echo "\033[1;34m📂 Compilation $<...\033[0m"
	@$(COMP) $(CFLAG) -c $< -o $@
	@echo "\033[1;32m✅ $< compilé !\033[0m"

clean: clear_terminal
	@echo "\033[1;31m🧹 Suppression des .o...\033[0m"
	@rm -f $(OBJ)
	@echo "\033[1;32m🗑️ .o supprimés.\033[0m"

fclean: clean
	@echo "\033[1;31m🔥 Suppression $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[1;32m🔥 $(NAME) supprimé.\033[0m"

re: fclean all

.PHONY: all clean fclean re clear_terminal
