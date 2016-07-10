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

#endif
