/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:30:51 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/06 14:30:52 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_shell *head, int show)
{
	int	tmp;

	if (l_len(head->sa) <= 1)
		return (-1);
	tmp = head->sa->nb;
	head->sa = pop_elem(head->sa);
	head->sa = push_back_stack(head->sa, tmp);
	if (show)
		ft_putendl("ra");
	return (1);
}

int	ft_rb(t_shell *head, int show)
{
	int	tmp;

	if (l_len(head->sb) <= 1)
		return (-1);
	tmp = head->sb->nb;
	head->sb = pop_elem(head->sb);
	head->sb = push_back_stack(head->sb, tmp);
	if (show)
		ft_putendl("rb");
	return (1);
}

int	ft_rr(t_shell *head, int show)
{
	head->sa = push_back_stack(head->sa, head->sa->nb);
	head->sa = pop_elem(head->sa);
	head->sb = push_back_stack(head->sb, head->sb->nb);
	head->sb = pop_elem(head->sb);
	if (show)
		ft_putendl("rr");
	return (1);
}
