# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdebelle <tsanzey@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 18:33:59 by tsanzey           #+#    #+#              #
#    Updated: 2016/01/14 14:40:19 by tsanzey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker
SRC = main.c ft_atol.c ft_error.c ft_list_fn.c ft_push.c ft_reverse.c \
		ft_rotate.c ft_sorted.c ft_swap.c push_swap.c
SRC2 = checker.c ft_error.c ft_list_fn.c ft_atol.c gnl.c ft_push.c \
		ft_reverse.c ft_rotate.c ft_sorted.c ft_swap.c push_swap.c

OBJ = $(SRC:%.c=obj/%.o)
OBJ2 = $(SRC2:%.c=obj/%.o)

CXX = gcc
CXXFLAGS = -Wall -Werror -Wextra

INC = -I includes
LIB = libft/

all: $(NAME) $(NAME2)

$(NAME): obj $(OBJ)
	@make -s -C $(LIB)
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(INC) -L$(LIB) -lft -g

$(NAME2): obj $(OBJ2)
	@make -s -C $(LIB)
	@$(CXX) $(CXXFLAGS) -o $(NAME2) $(OBJ2) $(INC) -L$(LIB) -lft -g

obj/%.o: %.c
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c $< -I$(LIB)

obj:
	mkdir -p obj/

clean:
	@rm -rf obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean re