/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 17:17:03 by tsanzey           #+#    #+#             */
/*   Updated: 2016/05/15 17:17:13 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap(int *a, int *b)
{
	int	c;

	c = *b;
	*b = *a;
	*a = c;
}

int			swap_a(t_handler *shell)
{
	if (shell->size_a > 1)
	{
		printf("oui?\n");
		ft_swap(&shell->end_a->content, &shell->end_a->prev->content);
		return (1);
	}
	return (0);
}

int			swap_b(t_handler *shell)
{
	if (shell->size_b > 1)
	{
		ft_swap(&shell->end_b->content, &shell->end_b->prev->content);
		return (1);
	}
	return (0);
}

int			swap_s(t_handler *shell)
{
	int x;

	x = 0;
	x += swap_a(shell);
	x += swap_b(shell);
	return (x);
}

// int main(void)
// {
// 	int a, b;

// 	a = 43;
// 	b = 22;
// 	printf("a %d, b %d\n", a, b);
// 	ft_swap(&a, &b);
// 	printf("a %d, b %d\n", a, b);
// 	return (0);
// }