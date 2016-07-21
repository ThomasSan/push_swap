#include "push_swap.h"

int rotateA(s_shell *head)
{
	if (stack_list_len(head->stackA) <= 1)
		return (1);
	head->stackA = push_back_stack(head->stackA, head->stackA->nb);
	head->stackA = pop_elem(head->stackA);
	return(1);
}

int rotateB(s_shell *head)
{
	if (stack_list_len(head->stackB) <= 1)
		return (1);
	head->stackB = push_back_stack(head->stackB, head->stackB->nb);
	head->stackB = pop_elem(head->stackB);
	return(1);
}

int rotateR(s_shell *head)
{
	head->stackA = push_back_stack(head->stackA, head->stackA->nb);
	head->stackA = pop_elem(head->stackA);
	head->stackB = push_back_stack(head->stackB, head->stackB->nb);
	head->stackB = pop_elem(head->stackB);
	return (1);
}
