#include <stdio.h>
#include "push_swap.h"

s_stack	*ptr_to_lst(s_stack *stack)
{
	while(stack->next)
		stack = stack->next;
	return(stack);
}

int ft_rra(s_shell *head)
{
	s_stack *tmp;
	
	if (stack_list_len(head->stackA) <= 1)
		return (1);
	tmp = ptr_to_lst(head->stackA);
	head->stackA = push_front_stack(head->stackA, tmp->nb);
	tmp->prev->next = NULL;
	tmp = NULL;
	free(tmp);
	ft_putendl("rra");
	// show_list(head);
	return(1);
}

int ft_rrb(s_shell *head)
{	
	s_stack *tmp;
	
	if (stack_list_len(head->stackB) <= 1)
		return (1);
	tmp = ptr_to_lst(head->stackB);
	head->stackB = push_front_stack(head->stackB, tmp->nb);
	tmp->prev->next = NULL;
	tmp = NULL;
	free(tmp);
	ft_putendl("rrb");
	return(1);
}

int ft_rrr(s_shell *head)
{
	s_stack *tmpA;
	s_stack *tmpB;

	tmpA = ptr_to_lst(head->stackA);
	tmpB = ptr_to_lst(head->stackB);
	head->stackA = push_front_stack(head->stackA, tmpA->nb);
	head->stackB = push_front_stack(head->stackB, tmpB->nb);
	tmpA->prev->next = NULL;
	tmpB->prev->next = NULL;
	tmpA = NULL;
	tmpB = NULL;
	free(tmpA);
	free(tmpB);
	return (1);
}
