CC=gcc 
CPPFLAGS=-g -Wall -Wextra -Werror -Iincl
NAME=ft_ls
LIBFT=libft
LIBFTPRINTF=libftprintf
FILES=main.c ft_setflags.c ft_readdir.c ft_sortfiles.c ft_printfiles.c \
ft_fullpath.c ft_memerror.c del.c ft_numlen.c sort_by_name.c sort_by_time.c \
sort_by_size.c ft_longformat.c ft_elltotal.c ft_ellgroup.c ft_elluser.c \
ft_elltime.c ft_ellname.c ft_ellmode.c ft_ls.c
OBJECTS=$(FILES:.c=.o)
OBJSDIR=$(addprefix src/, $(OBJECTS))

all: $(NAME)

$(NAME): $(OBJSDIR)
	@make -C $(LIBFT)
	@make -C $(LIBFTPRINTF)
	@$(CC) $(CPPFLAGS) $(OBJSDIR) -L$(LIBFT) -lft -L$(LIBFTPRINTF) -lftprintf -o $(NAME)

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(LIBFTPRINTF)
	@rm -f $(OBJSDIR)

fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(LIBFTPRINTF)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
