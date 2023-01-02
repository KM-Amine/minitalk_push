NAME = client-server
CC = cc
CFLAGS = -Wall -Wextra -Werror -I .
RM = rm -rf
HEADER  = minitalk.h

CLIENT = client
SERVER = server

COBJ = client.o
SOBJ = server.o

BCLIENT = client_bonus 
BSERVER = server_bonus

BCOBJ = client_bonus.o client_bonus_utils.o
BSOBJ = server_bonus.o

LIBFT = libft/libft.a 

all: $(NAME)

$(NAME): $(LIBFT) $(CLIENT) $(SERVER) 

$(LIBFT) :
	$(MAKE) -C libft

$(CLIENT):$(COBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(COBJ)  -o $(CLIENT) 
$(SERVER):$(SOBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(SOBJ)  -o $(SERVER) 

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< 

bonus: $(LIBFT) $(BCLIENT) $(BSERVER)

$(BCLIENT):$(BCOBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(BCOBJ) -o $(BCLIENT)
$(BSERVER):$(BSOBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(BSOBJ) -o $(BSERVER)

clean:
	$(RM) $(COBJ) $(SOBJ) $(BCOBJ) $(BSOBJ)
	$(MAKE) fclean -C libft
fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(BSERVER) $(BCLIENT)
re: fclean all

bre: fclean bonus

.PHONY: all clean fclean re bonus