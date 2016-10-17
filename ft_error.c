/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:46:18 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/06 14:46:45 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_duplicate(t_stack *lst, int x, int y)
{
	if (x == y)
	{
		flush(lst, 0);
		exit(0);
	}
}

int		ft_isdigitx(int c, int i)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	if (c == '-' && i == 0)
		return (1);
	return (0);
}

int		result(t_shell *head)
{
	if (ft_sorted(head->sa) && l_len(head->sb) == 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}

int		check_digit(char *s)
{
	int		i;
	long	nb;

	i = 0;
	nb = ft_atol(s);
	if (nb > 2147483647 || nb < -2147483648)
		return (-1);
	if (ft_strcmp(s, "-") == 0)
		return (-1);
	while (s[i])
	{
		if (ft_isdigitx(s[i], i) == 0)
			return (-1);
		i++;
	}
	return (1);
}

int		flush(t_stack *lst, int x)
{
	t_stack *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = tmp->n;
		lst = NULL;
		free(lst);
		lst = tmp;
	}
	if (x == 0)
		ft_putendl_fd("Error", 2);
	return (0);
}
