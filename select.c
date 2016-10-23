/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:20:42 by tsanzey           #+#    #+#             */
/*   Updated: 2016/10/23 14:20:45 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		string_is_valid(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strcmp(str, "") == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
	if (i == j)
		return (0);
	return (1);
}

void	push_swap_suite(t_shell *head)
{
	while (l_len(head->sb) > 0)
	{
		while (l_len(head->sb) > 1 &&
				l_nb(head->sb) > head->sb->nb)
			ft_rrb(head, 1);
		ft_pa(head, 1);
		if (l_len(head->sb) > 1 && l_len(head->sa) > 1 &&
head->sa->nb > head->sa->n->nb && head->sb->nb < head->sb->n->nb)
			ft_ss(head, 1);
		else
		{
			if (head->sa->nb > head->sa->n->nb)
				ft_sa(head, 1);
			if (l_len(head->sb) > 1 &&
				head->sb->nb < head->sb->n->nb)
				ft_sb(head, 1);
		}
	}
}

void	small_swap(t_shell *h)
{
	while (l_len(h->sa) > 1)
	{
		if (l_len(h->sb) > 1 && h->sa->nb > h->sa->n->nb &&
h->sb->nb < h->sb->n->nb)
			ft_ss(h, 1);
		else if (h->sa->nb > h->sa->n->nb)
			ft_sa(h, 1);
		else if (l_len(h->sb) > 1 && h->sb->nb < h->sb->n->nb)
			ft_sb(h, 1);
		if (h->max == h->sa->nb || (l_len(h->sb) > 2 &&
h->sa->nb > h->sa->n->nb && h->sa->nb > h->sa->n->n->nb))
			ft_ra(h, 1);
		while (l_len(h->sa) > 2 &&
l_nb(h->sa) < h->sa->nb && l_nb(h->sa) < h->sa->n->nb)
			ft_rra(h, 1);
		if (l_len(h->sb) > 1 && l_nb(h->sb) > h->sb->nb)
			ft_rrb(h, 1);
		if (ft_sorted(h->sa))
			break ;
		ft_pb(h, 1);
		if (l_len(h->sb) > 2 && ((h->sb->nb < h->sb->n->nb
	&& h->sb->nb < h->sb->n->n->nb) || l_nb(h->sb) > h->sb->nb))
			ft_rb(h, 1);
	}
	push_swap_suite(h);
}

void	which_swap(t_shell *head)
{
	if (l_len(head->sa) >= 40)
		push_swap(head, INT_MIN, 0, 0);
	else
	{
		while (ft_sorted(head->sa) == 0)
			small_swap(head);
	}
}
