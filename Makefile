CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) client.c

$(NAME_SERVER):
	$(CC) $(CFLAGS) -o $(NAME_SERVER) server.c

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS):
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) client_bonus.c

$(NAME_SERVER_BONUS):
	$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) server_bonus.c

clean:
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

fclean: clean

re: fclean all

.PHONY: all bonus clean fclean re