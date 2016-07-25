#include "push_swap.h"

void	push_swap_suite(s_shell *head, int x)
{
	while (x > 0)
	{
		ft_pa(head);
		x--;
		if (x > 1 && head->stackA->nb > head->stackA->next->nb && head->stackB->nb < head->stackB->next->nb)
			ft_ss(head);
		else 
		{
			if (head->stackA->nb > head->stackA->next->nb)
				ft_sa(head);
			if (x > 1 && head->stackB->nb < head->stackB->next->nb)
				ft_sb(head);
		}
	}
}

void	push_swap(s_shell *head)
{
	int x;

	x = 0;
	while (stack_list_len(head->stackA) > 2)
	{
		if (head->stackA->nb > head->stackA->next->nb)
			ft_sa(head);
		ft_pb(head);
		x++;
		if (x > 1 && head->stackA->nb > head->stackA->next->nb && head->stackB->nb < head->stackB->next->nb)
			ft_ss(head);
		else 
		{
			if (head->stackA->nb > head->stackA->next->nb)
				ft_sa(head);
			if (x > 1 && head->stackB->nb < head->stackB->next->nb)
				ft_sb(head);
		}
		if (ft_sorted(head->stackA) && ft_rev_sorted(head->stackB))
			break ;
	}
	push_swap_suite(head, x);
}
