# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loulou <loulou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:11:55 by csenand           #+#    #+#              #
#    Updated: 2023/03/14 20:40:58 by loulou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

SRCS_DIR	=	./src/
SRCS_LST	= 	main.c \
				utils.c
				
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST))

OBJS_DIR	=	./obj/
OBJS_LST	=	$(patsubst %.c, %.o, $(SRCS_LST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LST))

HEADER_DIR	=	./include/
HEADER_LST	=	push_swap.h
HEADER	 	=	$(addprefix $(HEADER_DIR), $(HEADER_LST))

LIBFT_DIR	=	./lib/libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_H		=	$(LIBFT_DIR)include/libft.h

# -- Colors -- #
RESET	= \033[0m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m

# -- Executable's creation -- #
all : dir $(NAME)

# -- Compile library -- #
$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "✅ $(GREEN)$(NAME)'s exectuable successfully created. ✅     $(RESET)"

# -- Create all files .o (object) from files .c (source code) -- #
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@printf "🎛️  $(PURPLE)Compilation of $(YELLOW)$(notdir $<)\r$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# -- Create directory for *.o files -- #
dir:
	@mkdir -p $(OBJS_DIR)

# -- Removes objects -- #
clean :
	@make -C $(LIBFT_DIR) clean
	@printf "💥 $(RED)Removing $(NAME)'s objects... $(RESET)💥\n"
	@$(RM) $(OBJS_DIR)
	@printf "🗑️  $(CYAN)$(NAME)'s object successfully deleted.$(RESET) 🗑️\n"

# -- Removes objects (with clean) and executable -- #
fclean : clean
	@printf "💥 $(RED)Removing executable(s)... $(RESET)💥\n"
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@printf "🗑️  $(CYAN)Executable(s) and archive(s) successfully deleted.$(RESET) 🗑️\n"

# -- Removes objects and executable then remakes all -- #
re : fclean all

# -- Avoid file-target name conflicts -- #
.PHONY: all bonus clean fclean re