#include "push_swap.h"
#include <stdio.h>

s_stack	*push_back_stack(s_stack *head, char *s)
{
	s_stack	*tmp;
	s_stack	*new;

	tmp = head;
	if (!(new = (s_stack*)malloc(sizeof(s_stack))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->nb = ft_atoi(s);
	if (tmp == NULL)
		head = new;
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (head);
}

void	show_list(s_stack *head)
{
	while (head)
	{
		printf("%d\n", head->nb);
		head = head->next;
	}
}

int		main(int argc, char **argv)
{
	s_shell		*head;
	int			i;

	i = 0;
	if (argc == 1)
		return (0);
	if (!(head = (s_shell*)malloc(sizeof(s_shell*))))
		return (0);
	head->stackA = NULL;
	head->stackB = NULL;
	while (argv[++i])
		head->stackA = push_back_stack(head->stackA, argv[i]);
	return (0);
}