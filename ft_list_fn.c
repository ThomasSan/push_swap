/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:23:06 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/06 14:23:09 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		l_len(t_stack *head)
{
	int i;

	i = 0;
	while (head)
	{
		head = head->n;
		i++;
	}
	return (i);
}

t_stack	*push_back_stack(t_stack *head, int i)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = head;
	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->n = NULL;
	new->prev = NULL;
	new->nb = i;
	if (tmp == NULL)
		head = new;
	else
	{
		while (tmp->n)
			tmp = tmp->n;
		tmp->n = new;
		new->prev = tmp;
		head->prev = new;
	}
	return (head);
}

t_stack	*push_back_stack2(t_stack *head, int i)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = head;
	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->n = NULL;
	new->prev = NULL;
	new->nb = i;
	if (tmp == NULL)
		head = new;
	else
	{
		while (tmp->n)
		{
			error_duplicate(head, tmp->nb, i);
			tmp = tmp->n;
		}
		error_duplicate(head, tmp->nb, i);
		tmp->n = new;
		new->prev = tmp;
		head->prev = new;
	}
	return (head);
}

t_stack	*push_front_stack(t_stack *head, int i)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = head;
	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->n = NULL;
	new->prev = NULL;
	new->nb = i;
	if (tmp == NULL)
		head = new;
	else
	{
		new->n = head;
		head->prev = new;
		head = new;
	}
	return (head);
}

void	show_list(t_shell *head)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_b = head->sb;
	tmp_a = head->sa;
	ft_putstr("A: ");
	if (tmp_a == NULL)
		ft_putstr("is empty\n");
	while (tmp_a)
	{
		ft_putnbr(tmp_a->nb);
		ft_putchar(' ');
		printf("ptr %p\n", tmp_a);
		tmp_a = tmp_a->n;
	}
	ft_putchar('\n');
	ft_putstr("B: ");
	if (tmp_b == NULL)
		ft_putstr("is empty");
	while (tmp_b)
	{
		ft_putnbr(tmp_b->nb);
		ft_putchar(' ');
		tmp_b = tmp_b->n;
	}
	ft_putchar('\n');
}
