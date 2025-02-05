COMP = c++
CFLAG = -Wall -Werror -Wextra -g3 -std=c++98

NAME = Polymorphism

SRC =	Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		main.cpp


OBJ = $(SRC:.cpp=.o)

all: $(NAME)
	@echo "\033[32m💥 Compilation terminée avec succès ! 💥\033[0m"
	@echo "\033[33m🔨 Le projet est prêt à être utilisé ! 🎉\033[0m"

$(NAME): $(OBJ)
	@echo "\033[1;33m🔧 Liaison des fichiers objets en un exécutable...\033[0m"
	@$(MAKE) -s progress_bar
	@$(COMP) $(CFLAG) $(OBJ) -o $(NAME)
	@$(MAKE) -s done
	@echo "\033[32m🚀 Génération de $(NAME) terminée !\033[0m"

%.o: %.cpp
	@$(MAKE) -s progress_bar
	@echo "\033[1;34m📂 Compilation de $< en $@...\033[0m"
	@$(COMP) $(CFLAG) -c $< -o $@
	@$(MAKE) -s done
	@echo "\033[32m✅ $< compilé avec succès !\033[0m"

clean:
	@echo "\033[1;31m🧹 Suppression des fichiers objets...\033[0m"
	@rm -f $(OBJ)
	@echo "\033[32m🗑️ Fichiers objets supprimés.\033[0m"

fclean: clean
	@echo "\033[1;31m🔥 Suppression de l'exécutable $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[32m🔥 $(NAME) supprimé.\033[0m"

re: fclean all

progress_bar:
	@echo -n "\033[1;34m⏳ Chargement"
	@for i in $(shell seq 1 10); do \
		sleep 0.1; \
		echo -n "."; \
	done
	@echo "\033[0m"

done:
	@echo -n "\033[1;32m✅ "
	@for i in $(shell seq 1 3); do \
		sleep 0.2; \
		echo -n "."; \
	done
	@echo " terminé !\033[0m"


.PHONY: all clean fclean re progress_bar done dev
