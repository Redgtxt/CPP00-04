CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = job
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

exec:
	./$(NAME)

.PHONY: all clean fclean re