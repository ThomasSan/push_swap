/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:46:47 by tsanzey           #+#    #+#             */
/*   Updated: 2016/05/15 16:35:31 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(char *s)
{
	t_stack	*new;
	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->content = ft_atoi(s);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*push_front(char *s, t_stack *head)
{
	t_stack	*new;

	new = init_stack(s);
	if (!head)
		head = new;
	else
	{
		head->prev = new;
		new->next = head;
		head = new;
	}
	return (head);
}

void	init_shell(t_handler *shell)
{
	shell->list_a = NULL;
	shell->start_a = NULL;
	shell->end_a = NULL;
	shell->list_b = NULL;
	shell->start_b = NULL;
	shell->end_b = NULL;
	shell->size_a = 0;
	shell->size_b = 0;
}

void	ft_push_swap(t_handler *shell)
{
	int x;
	shell->size_a = size_stack(shell->list_a);
	shell->size_b = size_stack(shell->list_b);
	shell->start_a = shell->list_a;
	shell->start_b = shell->list_b;
	shell->end_a = get_first(shell->list_a);
	shell->end_b = get_first(shell->list_b);
	x = ft_issorted(shell);
	printf("size_a : %d, size_b : %d\n", shell->size_a, shell->size_b);
	push_b(shell);
	ft_display(*shell);
	printf("size_a : %d, size_b : %d\n", shell->size_a, shell->size_b);
	push_b(shell);
	ft_display(*shell);
	printf("size_a : %d, size_b : %d\n", shell->size_a, shell->size_b);
	rotate_r(shell);
	ft_display(*shell);
	printf("size_a : %d, size_b : %d\n", shell->size_a, shell->size_b);
	reverse_a(shell);
	ft_display(*shell);
	printf("size_a : %d, size_b : %d\n", shell->size_a, shell->size_b);
}

int		main(int ac, char **av)
{
	int			i;
	t_stack		*head;
	t_handler	shell;

	head = NULL;
	init_shell(&shell);
	if (ac < 2)
		return (0);
	i = 1;
	while (av[i])
	{
		head = push_front(av[i], head);
		i++;
	}
	shell.list_a = head;
	ft_display(shell);
	ft_push_swap(&shell);
	return (0);
}
