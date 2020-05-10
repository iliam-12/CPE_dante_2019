SRC	=	srcs/toolbox.c	\
		srcs/parfait.c	\
		srcs/generator.c	\
		srcs/imparfait.c	\
		srcs/little_fonctions.c

NAME = generator

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME)

clean:
	rm -rf *~ \#*\# .\#*

fclean: clean
	rm -f $(NAME)

re: fclean all clean