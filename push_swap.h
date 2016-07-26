#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct		t_stack
{
	int				nb;
	struct t_stack	*next;
	struct t_stack	*prev;
}					s_stack;

typedef	struct		t_shell
{
	struct t_stack	*stackA;
	struct t_stack	*stackB;
	int				min;
	int				max;
}					s_shell;

/*
**	Main functions
*/
void				push_swap(s_shell *head);
/*
**	Errors functions
*/
long				ft_atol(char *s);
int					check_digit(char *s);
int					flush(s_stack *lst, int x);
void				error_duplicate(s_stack *lst, int x, int y);
/*
**	Listwise functions
*/
int					stack_list_len(s_stack *head);
s_stack				*push_front_stack(s_stack *head, int i);
s_stack				*push_back_stack(s_stack *head, int i);
s_stack				*push_back_stack2(s_stack *head, int i);
s_stack				*pop_elem(s_stack *src);
/*
**	Basics operations
*/
int					ft_sa(s_shell *head);
int					ft_sb(s_shell *head);
int					ft_ss(s_shell *head);
int					ft_pb(s_shell *head);
int					ft_pa(s_shell *head);
void				swap_int(int *a, int *b);
int					ft_ra(s_shell *head);
int					ft_rb(s_shell *head);
int					ft_rr(s_shell *head);
int					ft_rra(s_shell *head);
int					ft_rrb(s_shell *head);
int					ft_rrr(s_shell *head);
/*
**	Sort functions
*/
int					ft_sorted(s_stack *head);
int					ft_rev_sorted(s_stack *head);
/*
**	Debug functions
*/
void				show_list(s_shell *head);
#endif
