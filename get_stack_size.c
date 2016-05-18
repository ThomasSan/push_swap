/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_size->c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42->fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 17:16:09 by tsanzey           #+#    #+#             */
/*   Updated: 2016/05/15 17:16:41 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		size_stack(t_stack *head)
{
	int i;

	i = 0;
	while(head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

t_stack	*get_first(t_stack *head)
{
	t_stack *tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_display(t_handler shell)
{
	printf("A: ");
	while (shell.list_a)
	{
		printf("%d ", shell.list_a->content);
		shell.list_a = shell.list_a->next;
	}
	printf("\nB: ");
	while (shell.list_b)
	{
		printf("%d ", shell.list_b->content);
		shell.list_b = shell.list_b->next;
	}
	printf("\n");
}

void	ft_actualize(t_handler *shell)
{
	shell->size_a = size_stack(shell->list_a);
	shell->size_b = size_stack(shell->list_b);
	shell->start_a = shell->list_a;
	shell->start_b = shell->list_b;
	shell->end_a = get_first(shell->list_a);
	shell->end_b = get_first(shell->list_b);
}