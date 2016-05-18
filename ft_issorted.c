/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 17:32:48 by tsanzey           #+#    #+#             */
/*   Updated: 2016/05/15 17:33:03 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		croissant(int a, int b)
{
	return (a <= b);
}

int		ft_issorted(t_handler *shell)
{
	int i;

	i = 0;
	while (i < shell->size_a && shell->size_a != 1)
	{
		if (!croissant(shell->start_a->content, shell->start_a->next->content))
			return (0);
		shell->start_a = shell->start_a->next;
	}
	if (shell->start_b == NULL && shell->end_b == NULL)
		return (1);
	return (0);
}