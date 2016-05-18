/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 17:17:43 by tsanzey           #+#    #+#             */
/*   Updated: 2016/05/15 17:17:52 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate_a(t_handler *shell)
{
	if (shell->size_a < 2)
		return (-1);
	shell->list_a = push_bottom(shell->list_a, shell->end_a->content);
	pop_last_elem(shell->list_a);
	ft_actualize(shell);
	return (0);
}

int		rotate_b(t_handler *shell)
{
	if (shell->size_b < 2)
		return (-1);
	shell->list_b = push_bottom(shell->list_b, shell->end_b->content);
	pop_last_elem(shell->list_b);
	ft_actualize(shell);
	return (0);
}

int		rotate_r(t_handler *shell)
{
	int x;
	int y;

	x = rotate_b(shell);
	y = rotate_a(shell);
	return (x + y);
}