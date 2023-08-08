SRC = main.cpp RPN.cpp

CC = g++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

OBJ = $(SRC:.cpp=.o)

NAME = RPN

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re