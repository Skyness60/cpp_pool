COMP = c++
CFLAG = -Wall -Werror -Wextra -g3 -std=c++98

NAME = leak_information

SRC = tests.cpp \
	  Account.cpp
OBJ = $(SRC:.cpp=.o)

TRUE_LOG = true.log

CHECK_LEAK_SH = check_leak.sh

all: $(NAME) $(TRUE_LOG) $(CHECK_LEAK_SH)
	@echo "\033[32m💻 Le checker && le fichier des logs est telecharger ! 💻\033[0m"
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
	@rm -rf $(TRUE_LOG) $(CHECK_LEAK_SH)
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

$(TRUE_LOG):
	@echo "[19920104_091532] index:0;amount:42;created" > $(TRUE_LOG)
	@echo "[19920104_091532] index:1;amount:54;created" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:2;amount:957;created" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:3;amount:432;created" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:4;amount:1234;created" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:5;amount:0;created" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:6;amount:754;created" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:7;amount:16576;created" >> $(TRUE_LOG)
	@echo "[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:1;amount:54;deposits:0;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:2;amount:957;deposits:0;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:3;amount:432;deposits:0;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:4;amount:1234;deposits:0;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:5;amount:0;deposits:0;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:6;amount:754;deposits:0;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:7;amount:16576;deposits:0;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:2;p_amount:957;deposit:564;amount:1521;nb_deposits:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:3;p_amount:432;deposit:2;amount:434;nb_deposits:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:4;p_amount:1234;deposit:87;amount:1321;nb_deposits:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:5;p_amount:0;deposit:23;amount:23;nb_deposits:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:6;p_amount:754;deposit:9;amount:763;nb_deposits:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:7;p_amount:16576;deposit:20;amount:16596;nb_deposits:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:1;amount:819;deposits:1;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:2;amount:1521;deposits:1;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:3;amount:434;deposits:1;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:4;amount:1321;deposits:1;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:5;amount:23;deposits:1;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:6;amount:763;deposits:1;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:7;amount:16596;deposits:1;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:0;p_amount:47;withdrawal:refused" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:5;p_amount:23;withdrawal:refused" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:1;amount:785;deposits:1;withdrawals:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:2;amount:864;deposits:1;withdrawals:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:3;amount:430;deposits:1;withdrawals:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:4;amount:1245;deposits:1;withdrawals:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:5;amount:23;deposits:1;withdrawals:0" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:6;amount:106;deposits:1;withdrawals:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:7;amount:8942;deposits:1;withdrawals:1" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:0;amount:47;closed" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:1;amount:785;closed" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:2;amount:864;closed" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:3;amount:430;closed" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:4;amount:1245;closed" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:5;amount:23;closed" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:6;amount:106;closed" >> $(TRUE_LOG)
	@echo "[19920104_091532] index:7;amount:8942;closed" >> $(TRUE_LOG)

$(CHECK_LEAK_SH):
	@curl -o $(CHECK_LEAK_SH) "https://cdn.discordapp.com/attachments/1238453543166410845/1313895655143379026/check_leak.sh?ex=6751cc2f&is=67507aaf&hm=410ff4fbce117c6636017b70847a2773480563a4a10c4a5aebf1a0e555f793e2&"
	@chmod +x $(CHECK_LEAK_SH)


.PHONY: all clean fclean re progress_bar done dev
