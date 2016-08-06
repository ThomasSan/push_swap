/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:28:58 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/06 14:28:59 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sorted(t_stack *head)
{
	t_stack *tmp;

	tmp = head->n;
	while (tmp)
	{
		if (head->nb > tmp->nb)
			return (0);
		tmp = tmp->n;
		head = head->n;
	}
	return (1);
}

int		ft_rev_sorted(t_stack *head)
{
	t_stack *tmp;

	tmp = head->n;
	while (tmp)
	{
		if (head->nb < tmp->nb)
			return (0);
		tmp = tmp->n;
		head = head->n;
	}
	return (1);
}
