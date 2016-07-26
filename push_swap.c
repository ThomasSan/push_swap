#include "push_swap.h"

int 	get_last_nb(s_stack *head)
{
	s_stack *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->nb);
}

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
	int lastA;

	x = 0;
	while (stack_list_len(head->stackA) > 2)
	{
		lastA = get_last_nb(head->stackA);
		if (head->max == head->stackA->nb)
			ft_ra(head);
		else if (head->min == lastA)
			ft_rra(head);
		if (x > 1 && head->stackA->nb > head->stackA->next->nb && head->stackB->nb < head->stackB->next->nb)
			ft_ss(head);
		else if (head->stackA->nb > head->stackA->next->nb)
			ft_sa(head);
		else if (x > 1 && head->stackB->nb < head->stackB->next->nb)
			ft_sb(head);
		if (ft_sorted(head->stackA))
			break ;
		ft_pb(head);
		x++;
	}
	push_swap_suite(head, x);
}
