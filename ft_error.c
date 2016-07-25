#include "push_swap.h"

void	error_duplicate(s_stack *lst, int x, int y)
{
	if (x == y)
	{
		flush(lst, 0);
		exit(0);
	}
}

int		ft_isdigitx(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

int		check_digit(char *s)
{
	int i;
	long nb;

	i = 0;
	nb = ft_atol(s);
	if (nb > 2147483647 || nb < -2147483648)
		return (-1);
	while (s[i])
	{
		if (ft_isdigitx(s[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}

int		flush(s_stack *lst, int x)
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
	if (x == 0)
		ft_putendl_fd("Error", 2);
	return (0);
}
