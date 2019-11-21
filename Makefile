LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		sources/ft_treatment.c \
		sources/ft_treat_width.c \
		sources/ft_u_itoa.c \
		sources/ft_ull_base.c \
		sources/ft_putchar.c \
		sources/ft_str_tolower.c \
		sources/ft_putstrprec.c \
		sources/ft_treat_string.c \
		sources/ft_treat_char.c \
		sources/ft_treat_pointer.c \
		sources/ft_treat_int.c \
		sources/ft_treat_uint.c \
		sources/ft_treat_percent.c \
		sources/ft_treat_hexa.c \
		sources/ft_treat_flags.c 
		
SURPL_O = 	ft_treat_width.o \
			ft_treatment.o \
			ft_treat_width.o \
			ft_u_itoa.o \
			ft_ull_base.o \
			ft_putchar.o \
			ft_str_tolower.o \
			ft_putstrprec.o \
			ft_treat_string.o \
			ft_treat_char.o \
			ft_treat_pointer.o \
			ft_treat_int.o \
			ft_treat_uint.o \
			ft_treat_percent.o \
			ft_treat_hexa.o \
			ft_treat_flags.o  

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
