#include <stdio.h>
#include "push_swap.h"

s_stack	*ptr_to_lst(s_stack *stack)
{
	while(stack->next)
		stack = stack->next;
	printf("stack %p\n", stack);
	return(stack);
}

int rrA(s_shell *head)
{
	s_stack *tmp;
	
	if (stack_list_len(head->stackA) <= 1)
		return (1);
	tmp = ptr_to_lst(head->stackA);
	head->stackA = push_front_stack(head->stackA, tmp->nb);
	printf("tmp %p\n", tmp);
	tmp->prev->next = NULL;
	tmp = NULL;
	free(tmp);
	return(1);
}

int rrB(s_shell *head)
{	
	if (stack_list_len(head->stackB) <= 1)
		return (1);
	head->stackB = push_front_stack(head->stackB, head->stackB->nb);
	head->stackB = pop_elem(head->stackB);
	return(1);
}

int rrR(s_shell *head)
{
	head->stackA = push_front_stack(head->stackA, head->stackA->nb);
	head->stackA = pop_elem(head->stackA);
	head->stackB = push_front_stack(head->stackB, head->stackB->nb);
	head->stackB = pop_elem(head->stackB);
	return (1);
}