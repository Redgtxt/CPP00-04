CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = ex00
SRC =   main.cpp Animal.cpp Dog.cpp Cat.cpp

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
