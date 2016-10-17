/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 13:00:36 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/06 13:00:39 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "checker.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int		get_index(char *s)
{
	int			i;
	static char	*cmd[] = {"sa", "sb", "ss", "pb", "pa",
	"ra", "rb", "rr", "rra", "rrb", "rrr"};

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(cmd[i], s) == 0)
			break ;
		i++;
	}
	return (i);
}

int		ft_check(t_shell *head, char *s)
{
	int		(*fun_array[11])(t_shell *head, int show);
	int		index;

	fun_array[0] = ft_sa;
	fun_array[1] = ft_sb;
	fun_array[2] = ft_ss;
	fun_array[3] = ft_pb;
	fun_array[4] = ft_pa;
	fun_array[5] = ft_ra;
	fun_array[6] = ft_rb;
	fun_array[7] = ft_rr;
	fun_array[8] = ft_rra;
	fun_array[9] = ft_rrb;
	fun_array[10] = ft_rrr;
	index = get_index(s);
	if (index < 11)
		fun_array[index](head, 0);
	else
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	return (1);
}

void	read_line(t_shell *head)
{
	char		*buff;

	buff = NULL;
	while (get_next_line(0, &buff))
	{
		ft_check(head, buff);
		free(buff);
	}
}

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

int		main(int argc, char **argv)
{
	t_shell		*head;
	int			i;

	i = argc == 2 ? 0 : 1;
	if (argc == 2 && ft_strcmp(argv[1], "") != 0)
		argv = ft_strsplit(argv[1], ' ');
	if (argc == 1 || !(head = (t_shell*)malloc(sizeof(t_shell*))))
		return (0);
	head->sa = NULL;
	head->sb = NULL;
	while (argv[i])
	{
		if (check_digit(argv[i]) == -1)
			return (flush(head->sa, 0));
		head->sa = push_back_stack2(head->sa, ft_atoi(argv[i++]));
	}
	read_line(head);
	result(head);
	free_lst(head);
	free(head);
	if (argc == 2)
		free_array(argv);
	return (0);
}
