#include "push_swap.h"

s_stack		*pop_elem(s_stack *src)
{
	s_stack		*tmp;

	tmp = src->next;
	free(src);
	src = NULL;
	return (tmp);
}

int			ft_push(s_stack *src, s_stack *dest)
{
	if(stack_list_len(src) < 1)
		return (-1);
	dest = push_front_stack(dest, src->nb);
	src = pop_elem(src);
	return (1);
}
