# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 09:58:36 by lleodev           #+#    #+#              #
#    Updated: 2024/12/13 17:39:46 by lleodev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -g
INCLUDES = -I./includes/ -I./libs/libft/

LIB = ./libs/libft/libft.a
COMPLIB = cd libs/libft/ && make

SRC =	./src/builtins/ft_echo.c		\
	./src/builtins/ft_echo_one.c		\
	./src/builtins/ft_echo_two.c		\
	./src/builtins/ft_cd.c				\
	./src/builtins/ft_cd_one.c			\
	./src/utils/ft_split_echo.c      	\
	./src/builtins/ft_unset.c			\
	./src/builtins/ft_builtins.c		\
	./src/builtins/ft_free_builtins.c	\
	./src/builtins/ft_export.c			\
	./src/builtins/ft_check_builtins.c	\
	./src/cmd_handler/split_commands.c	\
	./src/cmd_handler/commands_exist.c	\
	./src/cmd_handler/catch_cmd_args.c	\
	./src/cmd_handler/handle_cmd.c		\
	./src/cmd_handler/cmd_handler_utils.c\
	./src/token_handler/handle_quote.c	\
	./src/token_handler/handle_tokens.c	\
	./src/token_handler/token_handler_utils.c \
	./src/utils/ft_split_prec.c			\
	./src/utils/ft_split_prec_deli.c	\
	./src/utils/utils.c					\
	./src/utils/utils2.c					\
	./src/utils/ft_utils_one.c			\
	./src/utils/ft_comands.c			\
	./src/utils/ft_aux.c				\
	./src/utils/ft_aux1.c				\
	./src/utils/ft_aux2.c				\
	./src/utils/env.c					\
	./src/init_handler/var_initializer.c	\
	./src/signal_handler/ft_takesignal.c	\
	./src/free_handler/free.c			\
	./src/free_handler/free_handler_utils.c		\
	./src/redirects_handler/redirect_stdin.c	\
	./src/redirects_handler/redirect_stdout.c	\
	./src/redirects_handler/heredoc.c			\
	./src/redirects_handler/redirects_handler_utils.c	\
	./src/redirects_handler/redirects_handler_utils2.c	\
	./src/process_handler/path.c			\
	./src/process_handler/exec_bin.c		\
	./src/process_handler/child_process.c	\
	./src/process_handler/pipe_handler.c	\
	./src/process_handler/process_handler_utils.c		\
	./src/display_cli.c					\
	./src/minishell.c	\
	./src/list_commands.c

OBJ = $(SRC:./src/%.c=obj/%.o)

################################COLORS######################################

WHITE_TEXT = \033[1;37m
GREEN_TEXT = \033[1;32m
RED_TEXT = \033[1;31m
ORANGE_TEXT = \033[1;33m
BLUE_TEXT = \033[1;34m
GREEN_BG = \033[42m
RED_BG = \033[41m
ORANGE_BG = \033[43m
BLUE_BG = \033[44m
RESET = \033[0m
date= date

all: $(NAME)
	make lleodev_header
	@echo "$(GREEN_TEXT)>_ Project ready! $(RESET)"
	@echo "$(ORANGE_TEXT)>_ $(NAME) is now avaliable try run ./$(NAME)$(RESET)"

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(OBJ) -o $(NAME) $(LIB) -lreadline
	make lleodev_header
	@echo "$(GREEN_BG)All libs Compiled! $(RESET)"

obj/%.o: src/%.c
	clear
	@mkdir -p $(dir $@)
	make lleodev_header
	@echo "$(BLUE_BG)compiling $(NAME) sources...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIB):
	$(COMPLIB)
	
clean: lleodev_header
	@rm -rf ./obj
	@cd libs/libft && make clean
	make lleodev_header
	@echo "$(RED_BG)All objects cleaned! $(RESET)"
fclean: clean lleodev_header
	@rm -rf $(NAME)
	@cd libs/libft && make fclean
	make lleodev_header
	@echo "$(RED_BG)Project cleaned! $(RESET)"

norm_lleodev:
	@norminette ./src/process_handler	\
	./src/cmd_handler					\
	./src/free_handler					\
	./src/init_handler					\
	./src/token_handler					\
	./src/redirects_handler				\
	./src/display_cli.c					\
	./src/minishell.c					\
	./src/utils/utils.c					\
	./src/utils/utils2.c					\
	./includes/minishell_lleodev.h
				

lleodev_header:
	@clear
	@echo "$(RED_TEXT)>_ In search of incrible!$(RESET)🎓"
	@echo "$(GREEN_BG)$(WHITE_TEXT)>_Wellcome$(RESET)👋"
	@echo "$(GREEN_TEXT)"
	@echo " ___	  "	" ___	     "	" ________ "	"  _______    " "_______     "		" ________ "	"  ___     _____"
	@echo "/__/|	  "	"/__/|     "	"/_______/|"	" / 	   \ "	"/_______ \  "	    "/_______/|"	" /___/\    \____\ "
	@echo "|  ||	  "	"|  ||     "	"|  ||___/  "	"| \____/ |"	"|  ||    \ \ "  "|  ||___/  "		"\   \ \  /   / /"
	@echo "|  ||	  "	"|  ||     "	"|  ||___   "	"| /    \ |"	"|  ||    | | "  "|  ||___   "		" \   \ \/   / /"
	@echo "|  ||	  "	"|  ||     "	"|  |/___/  "	"| |    | |"	"|  ||    | | "  "|  |/___/  "		"  \   \/   / /"
	@echo "|  ||____ "	"|  ||____ "	"|  ||____  "	"| |    | |"	"|  ||    | | "  "|  ||____  "		"   \   \  / /"
	@echo "|  |/___/|"	"|  |/___/|"	"|  ||___/| "	"| \___/  |"	"|  ||   /  / "  "|  ||___/| "		"    \   \/ /"
	@echo "|_______|/"	"|_______|/"	"|_______|/ "	"\_______/ "	"|__||__/_ /  "	   "|_______|/ "	"     \__/\/ "
	@echo "$(RESET)"
	@echo "$(BLUE_TEXT)Makefile created by lleodev $(RESET)"
	@echo "$(BLUE_TEXT)" && date
	@echo "$(RESET)"
	
	
re: fclean all
