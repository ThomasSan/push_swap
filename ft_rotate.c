#include "push_swap.h"

int ft_ra(s_shell *head)
{
	if (stack_list_len(head->stackA) <= 1)
		return (-1);
	head->stackA = push_back_stack(head->stackA, head->stackA->nb);
	head->stackA = pop_elem(head->stackA);
	ft_putendl("ra");
	// show_list(head);
	return(1);
}

int ft_rb(s_shell *head)
{
	if (stack_list_len(head->stackB) <= 1)
		return (-1);
	head->stackB = push_back_stack(head->stackB, head->stackB->nb);
	head->stackB = pop_elem(head->stackB);
	ft_putendl("rb");
	return(1);
}

int ft_rr(s_shell *head)
{
	head->stackA = push_back_stack(head->stackA, head->stackA->nb);
	head->stackA = pop_elem(head->stackA);
	head->stackB = push_back_stack(head->stackB, head->stackB->nb);
	head->stackB = pop_elem(head->stackB);
	ft_putendl("rr");
	return (1);
}
