# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 13:46:51 by cdarci            #+#    #+#              #
#    Updated: 2020/01/06 18:37:53 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C=gcc
NAME=libftprintf.a
FLAGS=-Wall -Wextra -Werror
LIBFT=../get_next_line
DIR_S=src
DIR_O=temp
HEADER=incl
SOURCES=ft_printf.c\
pf_atoi.c\
pf_convc.c\
pf_convdi.c\
pf_convf.c\
pf_convo.c\
pf_convp.c\
pf_convs.c\
pf_convu.c\
pf_convx.c\
pf_itoa_base.c\
pf_itoa.c\
pf_parse.c\
pf_putchar.c\
pf_putcharntime.c\
pf_putn.c\
pf_putstr.c\
pf_setbasicflags.c\
pf_setflags.c\
pf_spec.c\
pf_strbzero.c\
pf_strjoindelboth.c\
pf_strjoindelfirst.c\
pf_strjoindelsecond.c\
pf_toupper.c\
pf_uitoa.c
SRCS=$(addprefix $(DIR_S)/,$(SOURCES))
OBJS=$(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libftgnl.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(C) $(FLAGS) -I$(HEADER) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
