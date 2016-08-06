/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:25:46 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/06 14:25:47 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_int(int *a, int *b)
{
	int c;

	c = *b;
	*b = *a;
	*a = c;
}

int			swap_list(t_stack *head)
{
	swap_int(&head->nb, &head->n->nb);
	return (1);
}

int			ft_sa(t_shell *head, int show)
{
	if (l_len(head->sa) <= 1)
		return (-1);
	if (swap_list(head->sa))
	{
		if (show)
			ft_putstr("sa\n");
		return (1);
	}
	return (-1);
}

int			ft_sb(t_shell *head, int show)
{
	if (l_len(head->sb) <= 1)
		return (-1);
	if (swap_list(head->sb))
	{
		if (show)
			ft_putstr("sb\n");
		return (1);
	}
	return (-1);
}

int			ft_ss(t_shell *head, int show)
{
	if (l_len(head->sa) <= 1 || l_len(head->sb) <= 1)
		return (-1);
	if (swap_list(head->sa) && swap_list(head->sb))
	{
		if (show)
			ft_putstr("ss\n");
		return (1);
	}
	return (-1);
}
