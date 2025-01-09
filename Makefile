NAME = pipex

LIBFT_D = ./libft

LIBFT = $(LIBFT_D)/libft.a

SRC = pipex.c \
      utils.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

CC = cc

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@make clean -s -C $(LIBFT_D)
	rm -fr $(OBJ)

fclean: clean
	@make fclean -s -C $(LIBFT_D)
	rm -fr $(NAME)

re: fclean all

$(LIBFT):
	@make all -s -C $(LIBFT_D)

.PHONY: all clean fclean
