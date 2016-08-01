#include "push_swap.h"

int		stack_list_len(s_stack *head)
{
	int i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

s_stack	*push_back_stack(s_stack *head, int i)
{
	s_stack	*tmp;
	s_stack	*new;

	tmp = head;
	if (!(new = (s_stack*)malloc(sizeof(s_stack))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->nb = i;
	if (tmp == NULL)
		head = new;
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		head->prev = new;
	}
	return (head);
}

s_stack	*push_back_stack2(s_stack *head, int i)
{
	s_stack	*tmp;
	s_stack	*new;

	tmp = head;
	if (!(new = (s_stack*)malloc(sizeof(s_stack))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->nb = i;
	if (tmp == NULL)
		head = new;
	else
	{
		while(tmp->next)
		{
			error_duplicate(head, tmp->nb, i);
			tmp = tmp->next;
		}
		error_duplicate(head, tmp->nb, i);
		tmp->next = new;
		new->prev = tmp;
		head->prev = new;
	}
	return (head);
}

s_stack	*push_front_stack(s_stack *head, int i)
{
	s_stack	*tmp;
	s_stack	*new;

	tmp = head;
	if (!(new = (s_stack*)malloc(sizeof(s_stack))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->nb = i;
	if (tmp == NULL)
		head = new;
	else
	{
		new->next = head;
		head->prev = new;
		head = new;
	}
	return (head);
}

void	show_list(s_shell *head)
{
	s_stack *tmpA = head->stackA;
	s_stack *tmpB = head->stackB;

	ft_putstr("A: ");
	if (tmpA == NULL)
		ft_putstr("is empty\n");
	while (tmpA)
	{
		ft_putnbr(tmpA->nb);
		ft_putchar(' ');
		tmpA = tmpA->next;
	}
	ft_putchar('\n');
	ft_putstr("B: ");
	if (tmpB == NULL)
		printf("is empty");
	while (tmpB)
	{
		ft_putnbr(tmpB->nb);
		ft_putchar(' ');
		tmpB = tmpB->next;
	}
	printf("\n");
}
