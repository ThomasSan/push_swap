/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:45:56 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/13 11:44:43 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_array(char **argv)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = argv;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(tmp);
}

void	init_head(t_shell *head)
{
	head->sa = NULL;
	head->sb = NULL;
	head->max = INT_MIN;
}

int		main(int argc, char **argv)
{
	t_shell		*head;
	int			i;

	i = argc == 2 ? 0 : 1;
	if (argc == 2 && string_is_valid(argv[1]))
		argv = ft_strsplit(argv[1], ' ');
	if (argc == 1 || !(head = (t_shell*)malloc(sizeof(t_shell))))
		return (0);
	init_head(head);
	while (argv[i])
	{
		if (check_digit(argv[i]) == -1)
			return (flush(head->sa, 0));
		head->sa = push_back_stack2(head->sa, ft_atoi(argv[i]));
		head->max = ft_atoi(argv[i]) > head->max ? ft_atoi(argv[i]) : head->max;
		i++;
	}
	head->len = l_len(head->sa);
	which_swap(head);
	free_lst(head);
	if (argc == 2)
		free_array(argv);
	if (head)
		free(head);
	return (0);
}
