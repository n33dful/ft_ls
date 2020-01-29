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

#----------------------------- Make Targets -----------------------------------#

LIBFT=libft
LIBFTGNL=gnl
LIBFTPRINTF=libftprintf

#------------------------------- Lib Path -------------------------------------#

LIBFTPATH=libft
LIBFTGNLPATH=get_next_line
LIBFTPRINTFPATH=ft_printf

#------------------------------------------------------------------------------#

all: $(LIBFT) $(LIBFTGNL) $(LIBFTPRINTF)

$(LIBFT):
	@make -C $(LIBFTPATH)
	@cp $(LIBFTPATH)/libft.a ./libft.a

$(LIBFTGNL):
	@make -C $(LIBFTGNLPATH)
	@cp $(LIBFTGNLPATH)/libftgnl.a ./libftgnl.a

$(LIBFTPRINTF):
	@make -C $(LIBFTPRINTFPATH)
	@cp $(LIBFTPRINTFPATH)/libftprintf.a ./libftprintf.a

clean:
	@make clean -C $(LIBFTPATH)
	@make clean -C $(LIBFTGNLPATH)
	@make clean -C $(LIBFTPRINTFPATH)

fclean: clean
	@rm -f libft.a
	@rm -f libftgnl.a
	@rm -f libftprintf.a
	@make fclean -C $(LIBFTPATH)
	@make fclean -C $(LIBFTGNLPATH)
	@make fclean -C $(LIBFTPRINTFPATH)

re: fclean all

.PHONY: $(LIBFT) $(LIBFTGNL) $(LIBFTPRINTF)
