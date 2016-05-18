/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:06:43 by tsanzey           #+#    #+#             */
/*   Updated: 2016/05/18 16:06:53 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_elem(int x)
{
	t_stack	*new;
	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->content = x;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*push_bottom(t_stack *list, int x)
{
	t_stack *new;

	new = NULL;	
	new = get_elem(x);
	if (!list)
		list = new;
	else
	{
		list->prev = new;
		new->next = list;
		list = new;
	}
	return (list);
}

t_stack	*push_back(t_stack *list, int x)
{
	t_stack *tmp;
	t_stack *new;

	tmp = list;
	if (list)
	while (tmp->next)
		tmp = tmp->next;
	new = get_elem(x);
	if (!list)
		list = new;
	else
	{
		tmp->next = new;
		new->prev = tmp;
	}
	return (list);
}

void	pop_last_elem(t_stack *list)
{
	t_stack *tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->prev)
		tmp->prev->next = NULL;
	else
		tmp = NULL;
	free(tmp);
}

t_stack	*pop_first_elem(t_stack *list)
{
	t_stack *tmp;

	tmp = list->next;
	if (!tmp)
		return (NULL);
	tmp->prev = NULL;
	free(list);
	list = tmp;
	return (list);
}