#include "push_swap.h"

s_stack		*pop_elem(s_stack *src)
{
	s_stack		*tmp;

	tmp = src->next;
	free(src);
	src = NULL;
	return (tmp);
}

int			ft_pushB(s_shell *head)
{
	if(stack_list_len(head->stackA) < 1)
		return (-1);
	head->stackB = push_front_stack(head->stackB, head->stackA->nb);
	head->stackA = pop_elem(head->stackA);
	return (1);
}

int			ft_pushA(s_shell *head)
{
	if(stack_list_len(head->stackB) < 1)
		return (-1);
	head->stackA = push_front_stack(head->stackA, head->stackB->nb);
	head->stackB = pop_elem(head->stackB);
	return (1);
}