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
	if (swap_list(head->stackA))
	{
		printf("sa\n");
		return (1);
	}
	return (-1);
}

int			ft_sb(s_shell *head)
{
	if (swap_list(head->stackB))
	{
		printf("sb\n");
		return (1);
	}
	return (-1);
}

int			ft_ss(s_shell *head)
{
	if (swap_list(head->stackA) &&swap_list(head->stackB))
	{
		printf("ss\n");
		return (1);
	}
	return (-1);
}
