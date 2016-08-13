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

#include "push_swap.h"

int		free_lst(t_shell *head)
{
	t_stack *tmp;

	while (head->sa)
	{
		tmp = head->sa;
		head->sa = head->sa->n;
		free(tmp);
		tmp = NULL;
	}
	while (head->sb)
	{
		tmp = head->sb;
		head->sb = head->sb->n;
		free(tmp);
		tmp = NULL;
	}
	head->sa = NULL;
	head->sb = NULL;
	head = NULL;
	return (0);
}

int		l_nb(t_stack *head)
{
	t_stack *tmp;

	tmp = head;
	while (tmp->n)
		tmp = tmp->n;
	return (tmp->nb);
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

void	push_swap(t_shell *h)
{
	while (l_len(h->sa) > 1)
	{
		if (h->max == h->sa->nb || (l_len(h->sb) > 2 &&
h->sa->nb > h->sa->n->nb && h->sa->nb > h->sa->n->n->nb))
			ft_ra(h, 1);
		while (l_len(h->sa) > 2 &&
l_nb(h->sa) < h->sa->nb && l_nb(h->sa) < h->sa->n->nb)
			ft_rra(h, 1);
		if (l_len(h->sb) > 1 && h->sa->nb > h->sa->n->nb
	&& h->sb->nb < h->sb->n->nb)
			ft_ss(h, 1);
		else if (h->sa->nb > h->sa->n->nb)
			ft_sa(h, 1);
		else if (l_len(h->sb) > 1 && h->sb->nb < h->sb->n->nb)
			ft_sb(h, 1);
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
