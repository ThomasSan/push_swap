/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:41:04 by tsanzey           #+#    #+#             */
/*   Updated: 2016/10/23 14:41:07 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_smallest(t_stack *list, int n)
{
	while (list)
	{
		if (list->nb < n)
			return (0);
		list = list->n;
	}
	return (1);
}

int		is_bigger(t_stack *list, int n, int min)
{
	if (list->nb == min || list->n->nb == min)
		return (0);
	if (list->nb < n && list->n->nb < n)
		return (1);
	return (0);
}

void	rb_or_rr(t_shell *head)
{
	if (is_smallest(head->sb, head->sa->nb) && head->sa->nb != head->min)
		ft_rr(head, 1);
	else
		ft_rb(head, 1);
}

int		where_is_next(t_shell *head)
{
	int		len;
	int		min;
	int		index;
	int		i;
	t_stack	*tmp;

	min = INT_MAX;
	len = l_len(head->sb);
	i = 0;
	tmp = head->sb;
	while (tmp)
	{
		if (min > tmp->nb)
		{
			min = tmp->nb;
			index = i;
		}
		i++;
		tmp = tmp->n;
	}
	if (index > (len / 2))
		return (0);
	else
		return (1);
}

void	while_smallest(t_shell *head)
{
	if (head->sa->nb > head->sa->n->nb && head->sa->n->nb != head->min &&
head->sa->nb != head->min)
		ft_sa(head, 1);
	if (l_nb(head->sa) > head->sa->nb && head->sa->nb != head->min)
	{
		ft_rra(head, 1);
		ft_sa(head, 1);
	}
	if (l_len(head->sb) > 2 && head->sb->nb > head->sb->n->nb &&
head->sb->nb > head->sb->n->n->nb)
		ft_rr(head, 1);
	else
		ft_ra(head, 1);
}
