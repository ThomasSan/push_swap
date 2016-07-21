#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>

typedef struct 		t_stack
{
	int 			nb;
	struct t_stack	*next;
	struct t_stack	*prev;
}					s_stack;

typedef	struct 		t_shell
{
	struct t_stack	*stackA;
	struct t_stack	*stackB;
}					s_shell;


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
int 				rotateA(s_shell *head);
int 				rotateB(s_shell *head);
int 				rotateR(s_shell *head);
int 				rrA(s_shell *head);
int 				rrB(s_shell *head);
int 				rrR(s_shell *head);
/*
**	Debug functions
*/
void				show_list(s_shell *head);
#endif
