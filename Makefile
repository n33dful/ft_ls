# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 21:25:45 by cdarci            #+#    #+#              #
#    Updated: 2020/01/27 16:16:43 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C=gcc
NAME=ft_ls
FLAGS=-g -Wall -Wextra -Werror
DIR_S=src
DIR_O=temp
HEADER=incl
SOURCES=ft_create_arglist.c\
ft_fullpath.c\
ft_longaboutfile.c\
ft_longfilemode.c\
ft_ls.c\
ft_numlen.c\
ft_printfiles.c\
ft_readdir.c\
ft_setflags.c\
lstdel_func.c\
lstsort_func.c\
main.c
SRCS=$(addprefix $(DIR_S)/,$(SOURCES))
OBJS=$(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make libftprintf -C library
	@$(C) $(FLAGS) $(OBJS) -I$(HEADER) -Llibrary -lftprintf -o $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@$(C) $(FLAGS) -I$(HEADER) -o $@ -c $<

clean:
	@make clean -C library
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C library
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
