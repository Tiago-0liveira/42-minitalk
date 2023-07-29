# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 20:21:53 by tiagoliv          #+#    #+#              #
#    Updated: 2023/07/28 20:34:15 by tiagoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
OBJ_FOLDER = obj/

CLIENT_DIR = client/
CLIENT_FILES = client.c

SERVER_DIR = server/
SERVER_FILES = server.c

COMMON_DIR = common/
COMMON_FILES = common.c

SOURCES = \
	$(addprefix $(CLIENT_DIR), $(CLIENT_FILES)) \
	$(addprefix $(SERVER_DIR), $(SERVER_FILES)) \

OBJECTS =  $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(NAME): $(OBJ_FOLDER) $(OBJECTS)
	$(AR) -r $@ $(addprefix $(OBJ_FOLDER), $(notdir $(OBJECTS)))

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $(OBJ_FOLDER)$(notdir $(<:.c=.o))

clean:
	rm -rf $(OBJ_FOLDER)* $(OBJ_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re