CC = c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98

NAME = Interface
SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
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