/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:49:04 by tsanzey           #+#    #+#             */
/*   Updated: 2016/05/15 14:43:52 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				content;
}					t_stack;

typedef struct		s_handler
{
	struct s_stack	*list_a;
	struct s_stack	*start_a;
	struct s_stack	*end_a;
	struct s_stack	*list_b;
	struct s_stack	*start_b;
	struct s_stack	*end_b;
	int				size_a;
	int				size_b;
}					t_handler;

int					ft_issorted(t_handler *shell);
int					size_stack(t_stack *head);
void				ft_display(t_handler shell);
int					swap_a(t_handler *shell);
int					swap_b(t_handler *shell);
int					swap_s(t_handler *shell);
t_stack				*get_first(t_stack *head);
int					push_b(t_handler *shell);
int					push_a(t_handler *shell);
t_stack				*push_back(t_stack *list, int x);
void				pop_last_elem(t_stack *list);
void				ft_actualize(t_handler *shell);
t_stack				*push_bottom(t_stack *list, int x);
t_stack				*pop_first_elem(t_stack *list);
int					rotate_b(t_handler *shell);
int					rotate_a(t_handler *shell);
int					rotate_r(t_handler *shell);
int					reverse_b(t_handler *shell);
int					reverse_a(t_handler *shell);
int					reverse_r(t_handler *shell);

#endif
