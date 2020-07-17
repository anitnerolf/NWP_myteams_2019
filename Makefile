##
## EPITECH PROJECT, 2020
## make
## File description:
## file
##

SRC_SERVER	=	src_server/main.c		\
				check_if_number.c		\
				src_server/start_server.c		\
				src_server/accept_clients.c		\
				src_server/handle_signals.c

SRC_CLIENT	=	src_client/main.c	\
			check_if_number.c	\
			src_client/client_connect.c	\
			src_client/print_usage.c

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

CFLAGS		= 	-Wall -Wextra -Werror

NAME_SERVER	=	myteams_server

NAME_CLIENT	=	myteams_cli

all:		$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJ_SERVER)
		gcc -o $(NAME_SERVER) $(OBJ_SERVER) $(CFLAGS)

$(NAME_CLIENT):	$(OBJ_CLIENT)
		gcc -o $(NAME_CLIENT) $(OBJ_CLIENT) $(CFLAGS) -pthread

clean:
		rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: 	clean
		rm -f $(NAME_SERVER) $(NAME_CLIENT)

re:		fclean all
