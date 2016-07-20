#include "push_swap.h"
#include <stdio.h>

void		swap_int(int *a, int *b)
{
	int c;

	c = *b;
	*b = *a;
	*a = c;
}

int			swap_list(s_stack *head)
{
	if (stack_list_len(head) <= 1)
		return (-1);
	swap_int(&head->nb, &head->next->nb);
	return (1);
}

int			ft_sa(s_shell *head)
{
	return (swap_list(head->stackA));
}

int			ft_sb(s_shell *head)
{
	return (swap_list(head->stackB));
}

int			ft_ss(s_shell *head)
{
	int		x;
	int		y;
			
	x = swap_list(head->stackA);
	y = swap_list(head->stackB);
	return (x + y);
}
