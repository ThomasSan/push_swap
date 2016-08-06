/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:23:42 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/06 14:23:44 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*pop_elem(t_stack *src)
{
	t_stack		*tmp;

	tmp = src->n;
	free(src);
	src = NULL;
	return (tmp);
}

int			ft_pb(t_shell *head, int show)
{
	if (l_len(head->sa) < 1)
		return (-1);
	head->sb = push_front_stack(head->sb, head->sa->nb);
	head->sa = pop_elem(head->sa);
	if (show)
		ft_putstr("pb\n");
	return (1);
}

int			ft_pa(t_shell *head, int show)
{
	if (l_len(head->sb) < 1)
		return (-1);
	head->sa = push_front_stack(head->sa, head->sb->nb);
	head->sb = pop_elem(head->sb);
	if (show)
		ft_putstr("pa\n");
	return (1);
}
