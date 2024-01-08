CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = Polymorphism
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I.

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -rf $(NAME)

re : 
	make fclean
	make all

.PHONY: clean all fclean re