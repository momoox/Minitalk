CLIENT_NAME = client
SERVER_NAME = server

CLIENT_SOURCES = client.c 
SERVER_SOURCES = server.c

CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJECTS)
		$(MAKE) -C ft_printf
		$(CC) $(CFLAGS) ft_printf/libftprintf.a $(CLIENT_OBJECTS) -o $(CLIENT_NAME)
$(SERVER_NAME): $(SERVER_OBJECTS)
		$(MAKE) -C ft_printf
		$(CC) $(CFLAGS) ft_printf/libftprintf.a $(SERVER_OBJECTS) -o $(SERVER_NAME)

%.o: %.c 
		$(CC) $(CFLAGS) -c $? -g3
clean:
		rm -f $(CLIENT_OBJECTS)
		rm -f $(SERVER_OBJECTS)
		$(MAKE) -C ft_printf clean

fclean: clean
		rm -f $(CLIENT_NAME)
		rm -f $(SERVER_NAME)
		$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re test