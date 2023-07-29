# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 20:21:53 by tiagoliv          #+#    #+#              #
#    Updated: 2023/07/29 15:48:03 by tiagoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
LIBFT = libft.a
LIBFT_DIR = libft/
OBJ_FOLDER = obj/

SERVER_OUTPUT = server
CLIENT_OUTPUT = client

CLIENT_DIR = client_src/
CLIENT_FILES = client.c

SERVER_DIR = server_src/
SERVER_FILES = server.c

CLIENT_SOURCES = $(addprefix $(CLIENT_DIR), $(CLIENT_FILES))
CLIENT_OBJS = $(CLIENT_SOURCES:$(CLIENT_DIR)%.c=$(OBJ_FOLDER)%.o)

SERVER_SOURCES = $(addprefix $(SERVER_DIR), $(SERVER_FILES))
SERVER_OBJS = $(SERVER_SOURCES:$(SERVER_DIR)%.c=$(OBJ_FOLDER)%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_FOLDER) $(LIBFT) $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT_DIR)$(LIBFT) -o $(SERVER_OUTPUT)

$(CLIENT): $(OBJ_FOLDER) $(LIBFT) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT_DIR)$(LIBFT) -o $(CLIENT_OUTPUT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(OBJ_FOLDER)%.o: $(CLIENT_DIR)%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_FOLDER)%.o: $(SERVER_DIR)%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_FOLDER)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(CLIENT_OUTPUT) $(SERVER_OUTPUT)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re