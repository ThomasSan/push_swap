/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 14:40:39 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/20 14:40:44 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		get_len(char **array, int ac)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	i = ac == 2 ? i : i - 1; 
	return (i);
}

int		*fill_array(char **array, int len, int ac)
{
	int	*arr;
	int i;
	int j;

	i = ac == 2 ? 0 : 1;
	j = 0;
	if (!(arr = (int *)malloc(sizeof(int) * len)))
		exit(0);
	while (array[i])
	{
		arr[j] = ft_atoi(array[i]);
		i++;
		j++;
	}
	return (arr);
}

int		*fill_array2(t_stack *head, int len)
{
	int	*arr;
	int i;

	i = 0;
	if (!(arr = (int *)malloc(sizeof(int) * len)))
		exit(0);
	while (i < len)
	{
		arr[i] = head->nb;
		head = head->n;
		i++;
	}
	return (arr);
}

int		*sort_array(int *array, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[i])
				swap_int(&array[j], &array[i]);
			j++;
		}
		i++;
	}
	return (array);
}

int		get_median(char **array, int ac)
{
	int	len;
	int	ret;
	int	index;
	int	*arr;

	len = get_len(array, ac);
	arr = fill_array(array ,len, ac);
	arr = sort_array(arr, len);
	index = len % 2 == 0 ? len / 2 - 1 : len / 2;
	ret = arr[index];
	free(arr);
	return (ret);
}