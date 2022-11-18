CXX		=	g++

NAME	=	containers

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp

HEADER  =   vector.hpp

OBJ		=	$(SRC:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -o $@ -c $<

$(NAME) : $(OBJ) $(HEADER)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re