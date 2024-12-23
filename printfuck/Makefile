# Variables
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include/
SRCS =	src/put_char.c src/put_str.c src/put_hexa.c src/put_hexa_min.c src/put_nbr.c src/put_octale.c src/put_pnt.c src/put_unsnbr.c src/ft_printf.c# Tous les fichiers sources
OBJS = $(SRCS:.c=.o)
INCLUDES = -I include/ # Indiquer le dossier des en-têtes

# Compilation de la bibliothèque
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS)

# Clean complet
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all
