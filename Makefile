CXX		=	g++

NAME	=	containers

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC		=	./srcs/main.cpp

HEADER  =   ./includes/map.hpp\
			./includes/set.hpp\
			./includes/stack.hpp\
			./includes/vector.hpp

OBJ		=	$(SRC:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $<

$(NAME) : $(OBJ) $(HEADER)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re