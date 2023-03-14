#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := push_swap
CC        	:= gcc
FLAGS    	:= -Wall -Wextra -Werror -g

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      lib/Libft/src/ft_strnstr.c \
                          lib/Libft/src/ft_isdigit.c \
                          lib/Libft/src/ft_lstadd_back.c \
                          lib/Libft/src/ft_putstr_fd.c \
                          lib/Libft/src/ft_lstnew.c \
                          lib/Libft/src/ft_strlcpy.c \
                          lib/Libft/src/ft_strlen.c \
                          lib/Libft/src/ft_atof.c \
                          lib/Libft/src/ft_atol.c \
                          lib/Libft/src/ft_lstlast.c \
                          lib/Libft/src/ft_memcmp.c \
                          lib/Libft/src/ft_putnbr_fd.c \
                          lib/Libft/src/ft_lstclear.c \
                          lib/Libft/src/ft_lstiter.c \
                          lib/Libft/src/ft_strchr.c \
                          lib/Libft/src/ft_striteri.c \
                          lib/Libft/src/ft_bzero.c \
                          lib/Libft/src/ft_strjoin.c \
                          lib/Libft/src/ft_isascii.c \
                          lib/Libft/src/ft_memcpy.c \
                          lib/Libft/src/ft_isprint.c \
                          lib/Libft/src/ft_putendl_fd.c \
                          lib/Libft/src/ft_lstmap.c \
                          lib/Libft/src/ft_lstsize.c \
                          lib/Libft/src/ft_toupper.c \
                          lib/Libft/src/ft_split.c \
                          lib/Libft/src/ft_lstadd_front.c \
                          lib/Libft/src/ft_strrchr.c \
                          lib/Libft/src/ft_isalpha.c \
                          lib/Libft/src/ft_memchr.c \
                          lib/Libft/src/ft_putchar_fd.c \
                          lib/Libft/src/ft_memset.c \
                          lib/Libft/src/ft_substr.c \
                          lib/Libft/src/ft_strncmp.c \
                          lib/Libft/src/ft_strmapi.c \
                          lib/Libft/src/ft_strtrim.c \
                          lib/Libft/src/ft_memmove.c \
                          lib/Libft/src/ft_strlcat.c \
                          lib/Libft/src/ft_calloc.c \
                          lib/Libft/src/ft_strdup.c \
                          lib/Libft/src/ft_atoi.c \
                          lib/Libft/src/ft_isalnum.c \
                          lib/Libft/src/ft_lstdelone.c \
                          lib/Libft/src/ft_itoa.c \
                          lib/Libft/src/ft_tolower.c \
                          src/utils.c \
                          src/main.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs $(GREEN)✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary $(GREEN)✔️"

re:			fclean all

.PHONY:		all clean fclean re