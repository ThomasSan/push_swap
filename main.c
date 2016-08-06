/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:45:56 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/06 14:45:57 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_shell		*head;
	int			i;

	i = argc == 2 ? 0: 1;
	if (argc == 2)
		argv = ft_strsplit(argv[1], ' ');
	if (argc == 1 || !(head = (t_shell*)malloc(sizeof(t_shell*))))
		return (0);
	head->sa = NULL;
	head->sb = NULL;
	head->max = -2147483648;
	head->min = 2147483647;
	while (argv[i])
	{
		if (check_digit(argv[i]) == -1)
			return (flush(head->sa, 0));
		head->sa = push_back_stack2(head->sa, ft_atoi(argv[i]));
		head->max = ft_atoi(argv[i]) > head->max ? ft_atoi(argv[i]) : head->max;
		i++;
	}
	while (ft_sorted(head->sa) == 0)
		push_swap(head);
	free_lst(head);
	while (1);
	return (0);
}
