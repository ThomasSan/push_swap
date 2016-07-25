#include <stdio.h>
#include "push_swap.h"

s_stack	*ptr_to_lst(s_stack *stack)
{
	while(stack->next)
		stack = stack->next;
	return(stack);
}

int rrA(s_shell *head)
{
	s_stack *tmp;
	
	if (stack_list_len(head->stackA) <= 1)
		return (1);
	tmp = ptr_to_lst(head->stackA);
	head->stackA = push_front_stack(head->stackA, tmp->nb);
	tmp->prev->next = NULL;
	tmp = NULL;
	free(tmp);
	return(1);
}

int rrB(s_shell *head)
{	
	s_stack *tmp;
	
	if (stack_list_len(head->stackA) <= 1)
		return (1);
	tmp = ptr_to_lst(head->stackA);
	head->stackA = push_front_stack(head->stackA, tmp->nb);
	tmp->prev->next = NULL;
	tmp = NULL;
	free(tmp);
	return(1);
}

int rrR(s_shell *head)
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
