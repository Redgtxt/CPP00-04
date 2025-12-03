CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Zombie
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

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