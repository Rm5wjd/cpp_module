CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = replace
SRCS = main.cpp
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
	rm -rf $(NAME) *.replace

re : 
	make fclean
	make all

.PHONY: clean all fclean re