# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 20:21:53 by tiagoliv          #+#    #+#              #
#    Updated: 2023/10/24 18:52:01 by tiagoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
LIBFT = libft.a
LIBFT_DIR = libft/
LIBFT_FILE = $(LIBFT_DIR)$(LIBFT)
OBJ_FOLDER = obj/

SERVER_OUTPUT = server
CLIENT_OUTPUT = client

CLIENT_DIR = client_src/

SERVER_DIR = server_src/
SERVER_FILES = server_utils.c

COMMON_DIR = utils/
COMMON_FILES = utils.c


SERVER_SOURCES = $(addprefix $(SERVER_DIR), $(SERVER_FILES))
SERVER_OBJS = $(SERVER_SOURCES:$(SERVER_DIR)%.c=$(OBJ_FOLDER)%.o)

COMMON_SOURCES = $(addprefix $(COMMON_DIR), $(COMMON_FILES))
COMMON_OBJS = $(COMMON_SOURCES:$(COMMON_DIR)%.c=$(OBJ_FOLDER)%.o)

OBJS = 	$(addprefix $(OBJ_FOLDER), $(SERVER_SOURCES:%.c=%.o))\
		$(addprefix $(OBJ_FOLDER), $(COMMON_SOURCES:%.c=%.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT_FILE) $(SERVER_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(COMMON_OBJS) $(SERVER_DIR)$(SERVER).c $(LIBFT_FILE) -o $(SERVER_OUTPUT)

$(CLIENT): $(LIBFT_FILE) $(CLIENT_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(COMMON_OBJS) $(CLIENT_DIR)$(CLIENT).c $(LIBFT_FILE) -o $(CLIENT_OUTPUT)

$(LIBFT_FILE):
	make -C $(LIBFT_DIR)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(COMMON_OBJS): $(COMMON_SOURCES)
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(SERVER_OBJS): $(SERVER_SOURCES)
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(CLIENT_OBJS): $(CLIENT_SOURCES)
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	rm -rf $(OBJ_FOLDER)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(CLIENT_OUTPUT) $(SERVER_OUTPUT)
	make -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all

.PHONY: all