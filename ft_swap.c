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
	swap_int(&head->nb, &head->next->nb);
	return (1);
}

int			ft_sa(s_shell *head)
{
	if (stack_list_len(head->stackA) <= 1)
		return (-1);
	if (swap_list(head->stackA))
	{
		ft_putstr("sa\n");
		return (1);
	}
	return (-1);
}

int			ft_sb(s_shell *head)
{
	if (stack_list_len(head->stackB) <= 1)
		return (-1);
	if (swap_list(head->stackB))
	{
		ft_putstr("sb\n");
		return (1);
	}
	return (-1);
}

int			ft_ss(s_shell *head)
{
	if (stack_list_len(head->stackA) <= 1 || stack_list_len(head->stackB) <= 1)
		return (-1);
	if (swap_list(head->stackA) &&swap_list(head->stackB))
	{
		ft_putstr("ss\n");
		return (1);
	}
	return (-1);
}