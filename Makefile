# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdebelle <tsanzey@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 18:33:59 by tsanzey           #+#    #+#              #
#    Updated: 2016/08/06 12:38:54 by tsanzey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker
SRC = main.c ft_atol.c ft_error.c ft_list_fn.c ft_push.c ft_reverse.c \
		ft_rotate.c ft_sorted.c ft_swap.c push_swap.c utils.c\
		select.c misc.c
SRC2 = checker.c ft_error.c ft_list_fn.c ft_atol.c gnl.c ft_push.c \
		ft_reverse.c ft_rotate.c ft_sorted.c ft_swap.c push_swap.c \
		select.c utils.c misc.c\

OBJ = $(SRC:%.c=obj/%.o)
OBJ2 = $(SRC2:%.c=obj/%.o)

CXX = gcc
CXXFLAGS = -Wall -Werror -Wextra

INC = -I includes
LIB = libft/

all: $(NAME) $(NAME2)

$(NAME): obj $(OBJ)
	@make re -s -C $(LIB)
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(INC) -L$(LIB) -lft -g

$(NAME2): obj $(OBJ2)
	@$(CXX) $(CXXFLAGS) -o $(NAME2) $(OBJ2) $(INC) -L$(LIB) -lft -g

obj/%.o: %.c
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c $< -I$(LIB)

obj:
	mkdir -p obj/

clean:
	@rm -rf obj

fclean: clean
	@rm -rf $(NAME) $(NAME2)
	@make fclean -C libft/

re: fclean all

.PHONY: fclean all clean re
