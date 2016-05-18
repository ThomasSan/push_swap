/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 17:18:06 by tsanzey           #+#    #+#             */
/*   Updated: 2016/05/15 17:18:16 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		reverse_a(t_handler *shell)
{
	int t;

	if (shell->size_a < 2)
		return (-1);
	t = shell->list_a->content;
	shell->list_a = pop_first_elem(shell->list_a);
	shell->list_a = push_back(shell->list_a, t);
	ft_actualize(shell);
	return (0);
}

int		reverse_b(t_handler *shell)
{
	int t;

	if (shell->size_b < 2)
		return (-1);
	t = shell->list_b->content;
	shell->list_b = pop_first_elem(shell->list_b);
	shell->list_b = push_back(shell->list_b, t);
	ft_actualize(shell);
	return (0);
}

int		reverse_r(t_handler *shell)
{
	int x;
	int y;

	x = reverse_b(shell);
	y = reverse_a(shell);
	return (x + y);
}