SERVER 			= server
CLIENT 			= client

SERVER_BONUS 	= server_bonus
CLIENT_BONUS 	= client_bonus

SRCS			= server.c client.c
SRCS_BONUS		= server_bonus.c client_bonus.c

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I. -g
NAME			= $(SERVER) $(CLIENT)
NAME_BONUS		= $(SERVER_BONUS) $(CLIENT_BONUS)

all:	$(NAME)

clean:
				$(RM) $(NAME)

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

bonus:			$(NAME_BONUS)

.PHONY:			all clean fclean re bonus
