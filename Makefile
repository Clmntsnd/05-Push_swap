# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loulou <loulou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 15:33:52 by loulou            #+#    #+#              #
#    Updated: 2023/02/08 15:49:04 by loulou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include 


# -- Colors -- #
BOLD	      = \033[1m
BLACK	      = \033[30;1m
RED		      = \033[31;1m
GREEN	      = \033[32;1m
YELLOW	      = \033[33;1m
BLUE	      = \033[34;1m
MAGENTA	      = \033[35;1m
CYAN	      = \033[36;1m
WHITE	      = \033[37;1m
RESET	      = \033[0m

NAME          = push_swap
CFLAGS        = -g -Wunreachable-code -fsanitize=address
# CFLAGS		= -g -Wall -Wextra -Werror -Ofast

HEADERS       = include/push_swap.h

LIBFT_BIN     = lib/00-Libft/bin
LIBFT_DIR     = lib/00-Libft
LIBFT_SRCS    = $(addprefix $(LIBFT_DIR)/, $(LIBFT_FILES))
OBJECTS_LIBFT = $(LIBFT_SRCS:$(LIBFT_DIR)/%.c=$(LIBFT_BIN)/%.o)

BIN_DIR       = bin
SRCS_DIR      = srcs
SRCS_FILE     = main.c utils.c \
				
SRCS         = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))
OBJECTS      = $(SRCS:$(SRCS_DIR)/%.c=$(BIN_DIR)/%.o)

all: makelibft $(NAME)

makelibft:
	@$(MAKE) -s -C $(LIBFT_DIR)

$(NAME): $(OBJECTS_LIBFT) $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) $(RESET) Compiled ✅"

$(BIN_DIR)/%.o: $(SRCS_DIR)/%.c ./include/so_long.h
	@mkdir -p ./bin
	@echo "$(YELLOW)$(BOLD)Compiling:$(RESET) $(notdir $<)"
	@$(CC) $(CFLAGS) -o $@ -c $<

run: all
	@./$(NAME) ./maps/map1.ber

debug:
	@$(CC) -g -Wunreachable-code $(SRCS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(BIN_DIR)
	@$(MAKE) -C libft clean
	@echo "$(GREEN)$(BOLD)OBJECTS $(RESET)cleaned 🧼"

fclean:
	@rm -rf $(BIN_DIR)
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@echo "$(GREEN)$(BOLD)$(NAME) $(RESET)cleaned 🧼"

re: fclean
	@$(MAKE) -e

.PHONY: all clean fclean re libmlx