CFLAGS = -Werror -Wall -Wextra
NAMEC = client
NAMES = server
SRCSC = client.c
SRCSS = server.c
OBJSC = $(SRCSC:c=o)
OBJSS = $(SRCSS:c=o)

all : $(OBJSC) $(OBJSS)
		make -C libft
		gcc $(CFLAGS) -o $(NAMEC) libft/libft.a $(OBJSC)
		gcc $(CFLAGS) -o $(NAMES) libft/libft.a $(OBJSS)
clean :
	rm -f *.o libft/*.o
fclean : clean
	rm -f server client linft/libft.a
re : fclean all

.PHONY : clean fclean re all