/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:21:33 by tsanzey           #+#    #+#             */
/*   Updated: 2016/10/23 14:21:36 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		free_lst(t_shell *head)
{
	t_stack *tmp;

	while (head->sa)
	{
		tmp = head->sa;
		head->sa = head->sa->n;
		free(tmp);
		tmp = NULL;
	}
	while (head->sb)
	{
		tmp = head->sb;
		head->sb = head->sb->n;
		free(tmp);
		tmp = NULL;
	}
	head->sa = NULL;
	head->sb = NULL;
	head = NULL;
	return (0);
}

int		l_nb(t_stack *head)
{
	t_stack *tmp;

	tmp = head;
	while (tmp->n)
		tmp = tmp->n;
	return (tmp->nb);
}

int		arr(int nb, int *array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (nb == array[i])
			return (1);
		i++;
	}
	return (0);
}

int		biggest_in_list(t_stack *list, int *array, int len, int x)
{
	int max;

	max = 2147483647;
	while (list)
	{
		if (list->nb < max && x < list->nb &&
!arr(list->nb, array, len))
			max = list->nb;
		list = list->n;
	}
	return (max);
}

int		*get_biggest(t_stack *list, int len, int x)
{
	int i;
	int	*array;

	i = 0;
	if (!(array = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	while (i < len)
	{
		array[i] = biggest_in_list(list, array, i, x);
		i++;
	}
	return (array);
}
