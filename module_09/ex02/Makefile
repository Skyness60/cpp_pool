COMP = c++
CFLAG = -Wall -Werror -Wextra -g3 -std=c++98 -MMD
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

NAME = PmergeMe

SRC = $(shell find $(SRC_DIR) -name "*.cpp")

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

DEP = $(OBJ:.o=.d)

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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "\033[1;34m📂 Compilation $<...\033[0m"
	@$(COMP) $(CFLAG) -I$(INC_DIR) -c $< -o $@
	@echo "\033[1;32m✅ $< compilé !\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean: clear_terminal
	@echo "\033[1;31m🧹 Suppression des .o et .d...\033[0m"
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;32m🗑️ .o et .d supprimés.\033[0m"

fclean: clean
	@echo "\033[1;31m🔥 Suppression $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[1;32m🔥 $(NAME) supprimé.\033[0m"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re clear_terminal
