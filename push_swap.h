#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
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
**	Errors functions
*/
long				ft_atol(char *s);
int					check_digit(char *s);
int					flush(s_stack *lst);
/*
**	Listwise functions
*/
int					stack_list_len(s_stack *head);
s_stack				*push_front_stack(s_stack *head, int i);
s_stack				*push_back_stack(s_stack *head, int i);
s_stack				*pop_elem(s_stack *src);
/*
**	Basics operations
*/
int					ft_sa(s_shell *head);
int					ft_sb(s_shell *head);
int					ft_ss(s_shell *head);
int					ft_pushB(s_shell *head);
int					ft_pushA(s_shell *head);
void				swap_int(int *a, int *b);
int					rotateA(s_shell *head);
int					rotateB(s_shell *head);
int					rotateR(s_shell *head);
int					rrA(s_shell *head);
int					rrB(s_shell *head);
int					rrR(s_shell *head);
/*
**	Sort functions
*/
int		ft_sorted(s_stack *head)
int		ft_rev_sorted(s_stack *head)
/*
**	Debug functions
*/
void				show_list(s_shell *head);
#endif
