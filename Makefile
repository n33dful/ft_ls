CC=gcc 
CPPFLAGS=-g -Wall -Wextra -Werror -Iincl
NAME=ft_ls
LIBNAME=libft.a
LIBFILES=ft_isprint.c\
ft_memccpy.c\
ft_putnbr.c\
ft_strequ.c\
ft_strnequ.c\
ft_isspace.c\
ft_memchr.c\
ft_putnbr_fd.c\
ft_striter.c\
ft_strnew.c\
ft_atoi.c\
ft_isupper.c\
ft_memcmp.c\
ft_putstr.c\
ft_striteri.c\
ft_strnstr.c\
ft_bzero.c\
ft_itoa.c\
ft_memcpy.c\
ft_putstr_fd.c\
ft_strjoin.c\
ft_strrchr.c\
ft_isalnum.c\
ft_lstadd.c\
ft_memdel.c\
ft_strcat.c\
ft_strlcat.c\
ft_strsplit.c\
ft_isalpha.c\
ft_lstdel.c\
ft_memmove.c\
ft_strchr.c\
ft_strlen.c\
ft_strstr.c\
ft_isascii.c\
ft_lstdelone.c\
ft_memset.c\
ft_strclr.c\
ft_strmap.c\
ft_strsub.c\
ft_isblank.c\
ft_lstiter.c\
ft_putchar.c\
ft_strcmp.c\
ft_strmapi.c\
ft_strtrim.c\
ft_iscntrl.c\
ft_lstmap.c\
ft_putchar_fd.c\
ft_strcpy.c\
ft_strncat.c\
ft_tolower.c\
ft_isdigit.c\
ft_lstnew.c\
ft_putendl.c\
ft_strdel.c\
ft_strncmp.c\
ft_toupper.c\
ft_islower.c\
ft_memalloc.c\
ft_putendl_fd.c\
ft_strdup.c\
ft_strncpy.c\
ft_lstlen.c\
ft_lstsort.c\
ft_lstmove.c
FILES=main.c\
ft_setflags.c\
ft_sortfiles.c\
ft_printfiles.c\
ft_readdir.c\
ft_permissions.c\
ft_fullpath.c
OBJECTS=$(FILES:.c=.o)
LIBOBJECTS=$(LIBFILES:.c=.o)
OBJSDIR=$(addprefix src/, $(OBJECTS))
LIBOBJDIR=$(addprefix libft/, $(LIBOBJECTS))

all: $(NAME) libft/$(LIBNAME)

$(NAME): $(OBJSDIR) libft/$(LIBNAME)
	$(CC) $(CPPFLAGS) $(OBJSDIR) -Llibft -lft -o $(NAME)

$(LIBNAME): libft/$(LIBNAME)

libft/$(LIBNAME): $(LIBOBJDIR)
	ar rc libft/$(LIBNAME) $(LIBOBJDIR)
	ranlib libft/$(LIBNAME)

clean:
	make -C libft/ clean
	rm -f $(OBJSDIR)

fclean:clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
