/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:27:46 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/06 14:27:47 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ptr_to_lst(t_stack *stack)
{
	while (stack->n)
		stack = stack->n;
	return (stack);
}

int		ft_rra(t_shell *head, int show)
{
	t_stack *tmp;

	if (l_len(head->sa) <= 1)
		return (1);
	tmp = ptr_to_lst(head->sa);
	head->sa = push_front_stack(head->sa, tmp->nb);
	tmp->prev->n = NULL;
	free(tmp);
	if (show)
		ft_putendl("rra");
	return (1);
}

int		ft_rrb(t_shell *head, int show)
{
	t_stack	*tmp;

	if (l_len(head->sb) <= 1)
		return (1);
	tmp = ptr_to_lst(head->sb);
	head->sb = push_front_stack(head->sb, tmp->nb);
	tmp->prev->n = NULL;
	free(tmp);
	if (show)
		ft_putendl("rrb");
	return (1);
}

int		ft_rrr(t_shell *head, int show)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = ptr_to_lst(head->sa);
	tmp_b = ptr_to_lst(head->sb);
	head->sa = push_front_stack(head->sa, tmp_a->nb);
	head->sb = push_front_stack(head->sb, tmp_b->nb);
	tmp_a->prev->n = NULL;
	tmp_b->prev->n = NULL;
	tmp_a = NULL;
	tmp_b = NULL;
	free(tmp_a);
	free(tmp_b);
	if (show)
		ft_putendl("rrr");
	return (1);
}
