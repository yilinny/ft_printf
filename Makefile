NAME = libft.a
FLAGS = -Wall -Werror -Wextra
OBJS = ft_mems.o ft_strlen.o ft_ctype.o ft_alpha.o ft_last.o ft_additional.o ft_itoa.o ft_fns.o ft_output.o ft_split.o

.PHONY: clean fclean all re
all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "library is built"

%.o : %.c
	cc $(FLAGS) -c $< -o $@

fclean: clean 
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all