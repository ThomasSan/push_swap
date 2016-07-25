#include "push_swap.h"

int		ft_sorted(s_stack *head)
{
	s_stack *tmp;

	tmp = head->next;
	while (tmp)
	{
		if (head->nb > tmp->nb)
			return (0);
		tmp = tmp->next;
		head = head->next;
	}
	return (1);
}

int		ft_rev_sorted(s_stack *head)
{
	s_stack *tmp;

	tmp = head->next;
	while (tmp)
	{
		if (head->nb < tmp->nb)
			return (0);
		tmp = tmp->next;
		head = head->next;
	}
	return (1);
}