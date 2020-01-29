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
FLAGS=-Wall -Wextra -Werror
DIR_S=src
DIR_O=temp
HEADER=incl
SOURCES=ft_create_arglist.c\
main.c\
ft_setflags.c\
ft_readdir.c\
ft_sortfiles.c\
ft_printfiles.c\
ft_fullpath.c\
lstdel_funcs.c\
ft_numlen.c\
lstsort_byname.c\
lstsort_bytime.c\
lstsort_bysize.c\
ft_longformat.c\
ft_elltotal.c\
ft_ellgroup.c\
ft_elluser.c \
ft_elltime.c\
ft_ellname.c\
ft_ellmode.c\
ft_ls.c
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
