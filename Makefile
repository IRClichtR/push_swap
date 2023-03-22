NAME		= push_swap
CORE_SRC	= 
SORT_SRC	= 
SWAP_SRC	= 
PRINTF_SRC	= 
LIBFT_SRC	= 
SRCS		= $(CORE_SRC) $(SORT_SRC) $(SWAP_SRC) $(PRINTF_SRC) $(LIBFT_SRC) 

CORE_O		= $(CORE_SRC:.c=.o)
SORT_O		= $(SORT_SRC:.c=.o)
SWAP_O		= $(SWAP_SRC:.c=.o)
PRINTF_O	= $(PRINTF_SRC:.c=.o)
LIBFT_O		= $(LIBFT_SRC:.c=.o) 
OBJS		= $(CORE_O) $(SORT_O) $(SWAP_O) $(PRINTF_O) $(LIBFT_O)

CC		= cc
CFLAGS		= -g -Werror -Wextra -Wall

all: $(NAME)
$(NAME): obj_dir
	$(CC) $(CFLAGS) -c $< -o $@
obj_dir: 
	mkdir OBJS && mv core_fcts/*.o OBJS
	mv swap_utils/*.o OBJS
	mv ft_printf/libft/*.o OBJS
	mv ft_printf/*.o OBJS
	mv sort_utils/*.o OBJS
re:
clean: rm -rf 
fclean: clean
	rm -f $(NAME)
.PHONY 
