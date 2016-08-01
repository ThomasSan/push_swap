#include "push_swap.h"

void	free_lst(s_shell *head)
{
	s_stack *tmp;
	while (head->stackA)
	{
		tmp = head->stackA;
		free(tmp);
		tmp = NULL;
		head->stackA = head->stackA->next;
	}
	head->stackA = NULL;
	head->stackB = NULL;
	free(head);
	head = NULL;
}

int 	get_last_nb(s_stack *head)
{
	s_stack *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->nb);
}

void	push_swap_suite(s_shell *head)
{
	while (stack_list_len(head->stackB) > 0)
	{
		// show_list(head);
		if (stack_list_len(head->stackB) > 1 && get_last_nb(head->stackB) > head->stackB->nb)
			ft_rrb(head);
		ft_pa(head);
		if (stack_list_len(head->stackB) > 1 && head->stackA->nb > head->stackA->next->nb && head->stackB->nb < head->stackB->next->nb)
			ft_ss(head);
		else 
		{
			if (head->stackA->nb > head->stackA->next->nb)
				ft_sa(head);
			if (stack_list_len(head->stackB) > 1 && head->stackB->nb < head->stackB->next->nb)
				ft_sb(head);
		}
		// if (!ft_sorted(head->stackA) && ft_rev_sorted(head->stackB))
		// 	break ;
	}
}

void	push_swap(s_shell *head)
{
	int lastA;
	int lastB;

	while (stack_list_len(head->stackA) > 1)
	{
		// show_list(head);
		lastA = get_last_nb(head->stackA);
		if (head->max == head->stackA->nb)
			ft_ra(head);
		if (lastA < head->stackA->nb && lastA < head->stackA->next->nb)
			ft_rra(head);
		if (stack_list_len(head->stackB) > 1 && head->stackA->nb > head->stackA->next->nb && head->stackB->nb < head->stackB->next->nb)
			ft_ss(head);
		else if (head->stackA->nb > head->stackA->next->nb)
			ft_sa(head);
		else if (stack_list_len(head->stackB) > 1 && head->stackB->nb < head->stackB->next->nb)
			ft_sb(head);
		if (stack_list_len(head->stackB) > 1 && lastB > head->stackB->nb)
			ft_rrb(head);
		if (ft_sorted(head->stackA))
			break ;
		ft_pb(head);
		// show_list(head);
		lastB = get_last_nb(head->stackB);
		// if (stack_list_len(head->stackB) > 1 && lastB > head->stackB->nb && lastA < head->stackA->nb)
			// ft_rr(head);
		if (stack_list_len(head->stackB) > 3 && ((head->stackB->nb < head->stackB->next->nb
			&& head->stackB->nb < head->stackB->next->next->nb) || lastB > head->stackB->nb))
			ft_rb(head);
	}
	push_swap_suite(head);
}
