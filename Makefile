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

SRCS        :=      lib/Libft/ft_strnstr.c \
                          lib/Libft/ft_isdigit.c \
                          lib/Libft/ft_lstadd_back.c \
                          lib/Libft/ft_putstr_fd.c \
                          lib/Libft/ft_lstnew.c \
                          lib/Libft/ft_strlcpy.c \
                          lib/Libft/ft_strlen.c \
                          lib/Libft/ft_atof.c \
                          lib/Libft/ft_atol.c \
                          lib/Libft/ft_lstlast.c \
                          lib/Libft/ft_memcmp.c \
                          lib/Libft/ft_putnbr_fd.c \
                          lib/Libft/ft_lstclear.c \
                          lib/Libft/ft_lstiter.c \
                          lib/Libft/ft_strchr.c \
                          lib/Libft/ft_striteri.c \
                          lib/Libft/ft_bzero.c \
                          lib/Libft/ft_strjoin.c \
                          lib/Libft/ft_isascii.c \
                          lib/Libft/ft_memcpy.c \
                          lib/Libft/ft_isprint.c \
                          lib/Libft/ft_putendl_fd.c \
                          lib/Libft/ft_lstmap.c \
                          lib/Libft/ft_lstsize.c \
                          lib/Libft/ft_toupper.c \
                          lib/Libft/ft_split.c \
                          lib/Libft/ft_lstadd_front.c \
                          lib/Libft/ft_strrchr.c \
                          lib/Libft/ft_isalpha.c \
                          lib/Libft/ft_memchr.c \
                          lib/Libft/ft_putchar_fd.c \
                          lib/Libft/ft_memset.c \
                          lib/Libft/ft_substr.c \
                          lib/Libft/ft_strncmp.c \
                          lib/Libft/ft_strmapi.c \
                          lib/Libft/ft_strtrim.c \
                          lib/Libft/ft_memmove.c \
                          lib/Libft/ft_strlcat.c \
                          lib/Libft/ft_calloc.c \
                          lib/Libft/ft_strdup.c \
                          lib/Libft/ft_atoi.c \
                          lib/Libft/ft_isalnum.c \
                          lib/Libft/ft_lstdelone.c \
                          lib/Libft/ft_itoa.c \
                          lib/Libft/ft_tolower.c \
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