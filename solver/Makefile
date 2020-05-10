NAME	= solver

CC	= gcc

RM	= rm -f

SRCS	= ./srcs/solver.c \
	  ./srcs/toolbox.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./includes/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
