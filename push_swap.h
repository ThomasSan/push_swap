/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:48:24 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/06 15:00:33 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct		s_stack
{
	int				nb;
	struct s_stack	*n;
	struct s_stack	*prev;
}					t_stack;

typedef	struct		s_shell
{
	struct s_stack	*sa;
	struct s_stack	*sb;
	int				min;
	int				max;
	int				med;
	int				len;
}					t_shell;

/*
**	Main functions
*/
void				q_sort(t_shell *head);
void				push_swap(t_shell *head, int x);
void				which_swap(t_shell *head);
/*
**	Median functions
*/
int 				get_median(char **array, int ac);
int					get_len(char **array, int ac);
int					*fill_array2(t_stack *head, int len);
int					*sort_array(int *array, int size);
/*
**	Errors functions
*/
int					string_is_valid(char *str);
int					result(t_shell *head);
long				ft_atol(char *s);
int					check_digit(char *s);
int					flush(t_stack *lst, int x);
void				error_duplicate(t_stack *lst, int x, int y);
/*
**	Listwise functions
*/
int					l_nb(t_stack *head);
int					l_len(t_stack *head);
int					free_lst(t_shell *head);
t_stack				*push_front_stack(t_stack *head, int i);
t_stack				*push_back_stack(t_stack *head, int i);
t_stack				*push_back_stack2(t_stack *head, int i);
t_stack				*pop_elem(t_stack *src);
t_stack				*ptr_to_lst(t_stack *stack);
/*
**	Basics operations
*/
int					ft_sa(t_shell *head, int show);
int					ft_sb(t_shell *head, int show);
int					ft_ss(t_shell *head, int show);
int					ft_pb(t_shell *head, int show);
int					ft_pa(t_shell *head, int show);
void				swap_int(int *a, int *b);
int					ft_ra(t_shell *head, int show);
int					ft_rb(t_shell *head, int show);
int					ft_rr(t_shell *head, int show);
int					ft_rra(t_shell *head, int show);
int					ft_rrb(t_shell *head, int show);
int					ft_rrr(t_shell *head, int show);
/*
**	Sort functions
*/
void				swap_int(int *a, int *b);
int					ft_sorted(t_stack *head);
int					ft_rev_sorted(t_stack *head);
/*
**	Debug functions
*/
void				show_list(t_shell *head);

#endif
