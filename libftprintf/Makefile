# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 15:59:54 by cdarci            #+#    #+#              #
#    Updated: 2019/11/04 20:17:21 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc 
CPPFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
FILES=ft_parse.c\
ft_setflagsprnf.c\
ft_putn.c\
ft_spec.c\
ft_strbzero.c\
ft_convf.c\
ft_uitoa.c\
ft_convu.c\
ft_strjoinf.c\
ft_strjoindelboth.c\
ft_strjoindelfirst.c\
ft_strjoindelsecond.c\
ft_convo.c\
ft_convx.c\
ft_convdi.c\
ft_setbasicflags.c\
ft_convs.c\
ft_convc.c\
ft_convp.c\
ft_printf.c\
ft_strrew.c\
ft_itoa_base.c\
ft_putcharntime.c\
ft_strnewf.c\
ft_atoif.c\
ft_putstrf.c\
ft_itoaf.c\
ft_strlenf.c\
ft_strsubf.c\
ft_putnbrf.c\
ft_putcharf.c\
ft_strcpyf.c\
ft_strdelf.c\
ft_toupperf.c\
ft_memallocf.c\
ft_strdupf.c\
ft_strncpyf.c\
ft_strmapf.c 
OBJECTS = $(FILES:.c=.o)
OBJSDIR=$(addprefix src/, $(OBJECTS))

all: $(NAME)

$(NAME): $(OBJSDIR)
	ar rcs $(NAME) $(OBJSDIR)
	ranlib $(NAME)

clean:
	rm -f $(OBJSDIR)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
