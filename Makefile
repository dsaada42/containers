CXX		=	g++

NAME	=	containers

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC		=	./srcs/main.cpp\
			./srcs/map.cpp\
			./srcs/set.cpp\
			./srcs/stack.cpp\
			./srcs/vector.cpp

HEADER  =   ./includes/map.cpp\
			./includes/set.cpp\
			./includes/stack.cpp\
			./includes/vector.cpp

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