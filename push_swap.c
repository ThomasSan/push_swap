/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 12:43:08 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/06 13:02:48 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	while_bigger(t_shell *head)
{
	if (where_is_next(head) == 1)
		ft_rb(head, 1);
	else
		ft_rrb(head, 1);
}

void	sort_b_list(t_shell *head, int *biggest, int len)
{
	if (l_len(head->sb) <= 1)
		return ;
	if (head->sb->nb > l_nb(head->sb))
		ft_rb(head, 1);
	if (head->sb->nb > head->sb->n->nb)
	{
		if (arr(head->sa->nb, biggest, len) &&
arr(head->sa->n->nb, biggest, len) && head->sa->n->nb > head->sa->nb)
			ft_ss(head, 1);
	}
}

void	rempile(t_shell *head)
{
	if (l_nb(head->sa) > head->sa->nb)
		ft_rra(head, 1);
	while (l_len(head->sb) > 1)
	{
		if (l_len(head->sb) > 2 && head->sb->nb > head->sb->n->nb &&
head->sb->nb > head->sb->n->n->nb)
			rb_or_rr(head);
		while (is_bigger(head->sa, head->sb->nb, head->min))
			while_bigger(head);
		ft_pa(head, 1);
		if (head->sa->nb > head->sa->n->nb && head->sa->n->nb != head->min)
		{
			if (l_len(head->sb) > 1 && head->sb->nb > head->sb->n->nb)
				ft_ss(head, 1);
			else
				ft_sa(head, 1);
		}
		while (is_smallest(head->sb, head->sa->nb) && !ft_sorted(head->sa))
			while_smallest(head);
	}
	ft_pa(head, 1);
	if (head->sa->nb > head->sa->n->nb && head->sa->n->nb != head->min)
		ft_sa(head, 1);
	ft_ra(head, 1);
}

void	finish(t_shell *h)
{
	while (h->sa->nb > l_nb(h->sa))
		ft_ra(h, 1);
}

void	push_swap(t_shell *h, int x, int len, int i)
{
	int *big;

	len = l_len(h->sa) / 2;
	big = get_biggest(h->sa, len, x);
	h->min = x == INT_MIN ? big[0] : h->min;
	i = len;
	while (i)
	{
		if (arr(h->sa->nb, big, len) && arr(h->sa->n->nb, big, len) &&
h->sa->n->nb > h->sa->nb)
			ft_sa(h, 1);
		if (arr(h->sa->nb, big, len))
		{
			ft_pb(h, 1);
			i--;
		}
		else
			ft_ra(h, 1);
		sort_b_list(h, big, len);
	}
	rempile(h);
	if (x == INT_MIN)
		push_swap(h, big[len - 1], 0, 0);
	free(big);
	finish(h);
}
