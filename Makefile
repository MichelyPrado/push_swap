# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 10:04:20 by msilva-p          #+#    #+#              #
#    Updated: 2022/12/18 10:04:20 by msilva-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

FILES		=	error.c main.c movements_a.c movements_b.c movements_both.c \
				movements_utils.c organizer.c utils.c
OBJS		=	$(FILES:%.c=%.o)

CFLAGS		=	-Wall -Werror -Wextra

INCLUDE		=	-I $(LIBFT_DIR) -I includes

%.o: %.c
	cc $(CFLAGS) $(INCLUDE) -c $< -o $@

all: libft $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $@

libft:
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libft
