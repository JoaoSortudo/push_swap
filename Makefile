# # Nome do binário final
# NAME = push_swap

# # Compilador e flags
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# # Diretório da libft
# LIBFT_DIR = ../libft
# LIBFT = $(LIBFT_DIR)/libft.a

# # Fontes e objetos
# SRC = push_swap.c utils.c stack.c validate.c operations.c operationsA.c operationsB.c radix.c small_sort.c
# OBJ = $(SRC:.c=.o)

# # Regras principais
# all: $(LIBFT) $(NAME)

# # Compilar push_swap
# $(NAME): $(OBJ) $(LIBFT)
# 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# # Compilar a libft
# $(LIBFT):
# 	@$(MAKE) -C $(LIBFT_DIR)

# # Limpar objetos de push_swap
# clean:
# 	rm -f $(OBJ)
# 	@$(MAKE) clean -C $(LIBFT_DIR)

# # Limpar tudo
# fclean: clean
# 	rm -f $(NAME)
# 	@$(MAKE) fclean -C $(LIBFT_DIR)

# # Recompilar tudo
# re: fclean all

# .PHONY: all clean fclean re
NAME = push_swap
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SRC = push_swap.c utils.c stack.c validate.c small_sort.c radix.c operations.c operationsA.c operationsB.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) # Gera o executável

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
