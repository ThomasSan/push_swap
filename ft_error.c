#include "push_swap.h"

int		check_digit(char *s)
{
	int i;

	i = 0;
	if (ft_atol(s) > 2147483647)
		return (-1);
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}

int		flush(s_stack *lst)
{
	s_stack *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		lst = NULL;
		free(lst);
		lst = tmp;
	}
	ft_putendl_fd("Error", 2);
	return (0);
}
