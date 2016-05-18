/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 17:17:22 by tsanzey           #+#    #+#             */
/*   Updated: 2016/05/15 17:17:34 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			push_a(t_handler *shell)
{
	if (shell->size_b < 1)
		return (-1);
	shell->list_a = push_back(shell->list_a, shell->end_b->content);
	pop_last_elem(shell->list_b);
	ft_actualize(shell);
	return (0);
}

int			push_b(t_handler *shell)
{
	if (shell->size_a < 1)
		return (-1);
	shell->list_b = push_back(shell->list_b, shell->end_a->content);
	pop_last_elem(shell->list_a);
	ft_actualize(shell);
	return (0);
}
