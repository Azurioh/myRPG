##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## All rules to build the program
##

NAME	=	my_rpg

SRC =   $(shell find src -name '*.c')

OBJ		=	$(SRC:.c=.o)

CSFML_FLAGS    = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS += -Werror -Wall -Wextra -g

MAC_INCLUDES    =	-I/opt/homebrew/Cellar/csfml/2.6/include     \
                	-L/opt/homebrew/Cellar/csfml/2.6/lib

ifeq ($(UNAME_S),Darwin)
    CFLAGS += $(MAC_INCLUDES)
endif

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -g -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window \
		-lcsfml-system \
		-lcsfml-audio -lcsfml-network -lm

apple:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFML_FLAGS) $(MAC_INCLUDES)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
