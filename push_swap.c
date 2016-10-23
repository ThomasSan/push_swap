/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 12:43:08 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/06 13:02:48 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

int 	is_in_array(int nb, int *array, int len)
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

int 	biggest_in_list(t_stack *list, int *array, int len, int x)
{
	int max;

	max = 2147483647;
	while (list)
	{
		if (list->nb < max && x < list->nb && !is_in_array(list->nb, array, len))
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

void	show_array(int *array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("array[%d] = %d\n", i, array[i]);
		i++;
	}
}

void	sort_b_list(t_shell * head, int *biggest, int len)
{
	if (l_len(head->sb) <= 1)
		return ;
	if (head->sb->nb > l_nb(head->sb))
		ft_rb(head, 1);
	if (head->sb->nb > head->sb->n->nb)
	{
		if (is_in_array(head->sa->nb, biggest, len) && is_in_array(head->sa->n->nb, biggest, len) && head->sa->n->nb > head->sa->nb)
			ft_ss(head, 1);
		// else
		// 	ft_sb(head, 1);
	}
}

int		is_smallest(t_stack *list, int n)
{
	while (list)
	{
		if (list->nb < n)
			return (0);
		list = list->n;
	}
	return (1);
}

int		is_bigger(t_stack *list, int n, int min)
{
	if (list->nb == min || list->n->nb == min)
		return (0);
	if (list->nb < n && list->n->nb < n)
		return (1);
	return (0);
}

void	rb_or_rr(t_shell *head)
{
	if (is_smallest(head->sb, head->sa->nb) && head->sa->nb != head->min)
		ft_rr(head, 1);
	else
		ft_rb(head, 1);
}

int		where_is_next(t_shell *head)
{
	int		len;
	int		min;
	int		index;
	int		i;
	t_stack	*tmp;

	min = INT_MAX;
	len = l_len(head->sb);
	i = 0;
	tmp = head->sb;
	while(tmp)
	{
		if (min > tmp->nb)
		{
			min = tmp->nb;
			index = i;
		}
		i++;
		tmp = tmp->n;
	}
	if (index > (len / 2))
		return (0);
	else
		return (1);
}

void	while_smallest(t_shell *head)
{
	// show_list(head);
	if (head->sa->nb > head->sa->n->nb && head->sa->n->nb != head->min && head->sa->nb != head->min)
		ft_sa(head, 1);
	if (l_nb(head->sa) > head->sa->nb && head->sa->nb != head->min)
	{
		ft_rra(head, 1);
		ft_sa(head, 1);
	}
	if (l_len(head->sb) > 2 && head->sb->nb > head->sb->n->nb && head->sb->nb > head->sb->n->n->nb)
		ft_rr(head, 1);
	// else if (l_len(head->sb) > 2 && is_smallest(head->sb, head->sb->n->nb))
	// 	ft_rr(head, 1);
	else
		ft_ra(head, 1);
}

void	while_bigger(t_shell *head)
{
	// show_list(head);
	if (where_is_next(head) == 1)
		ft_rb(head, 1);
	else
		ft_rrb(head, 1);
}

void	rempile(t_shell *head)
{
	// show_list(head);
	if (l_nb(head->sa) > head->sa->nb)
		ft_rra(head, 1);
	while (l_len(head->sb) > 1)
	{
		// show_list(head);
		if (l_len(head->sb) > 2 && head->sb->nb > head->sb->n->nb && head->sb->nb > head->sb->n->n->nb)
			rb_or_rr(head);
		while (is_bigger(head->sa, head->sb->nb, head->min))
			while_bigger(head);
		ft_pa(head, 1);
		if (head->sa->nb > head->sa->n->nb && head->sa->n->nb != head->min)
		{
			if (l_len(head->sb) > 1 && head->sb->nb > head->sb->n->nb)
				ft_ss(head, 1);
			else
				ft_sa(head, 1);
		}
		while (is_smallest(head->sb, head->sa->nb) && !ft_sorted(head->sa))
			while_smallest(head);
	}
	ft_pa(head, 1);
	if (head->sa->nb > head->sa->n->nb && head->sa->n->nb != head->min)
		ft_sa(head, 1);
	ft_ra(head, 1);
}

void	push_swap(t_shell *h, int x)
{
	int len;
	int i;
	int *biggest;
	
	len = l_len(h->sa);
	len /= 2;
	biggest = get_biggest(h->sa, len, x);
	// show_array(biggest, len);
	if (x == INT_MIN)
		h->min = biggest[0];
	i = len;
	while (i)
	{
		// show_list(h);
		if (is_in_array(h->sa->nb, biggest, len) && is_in_array(h->sa->n->nb, biggest, len) && h->sa->n->nb > h->sa->nb)
			ft_sa(h, 1);
		if (is_in_array(h->sa->nb, biggest, len))
		{
			ft_pb(h, 1);
			i--;
		}
		else
			ft_ra(h, 1);
		sort_b_list(h, biggest, len);
	}
	rempile(h);
	// show_list(h);
	if (x == INT_MIN)
		push_swap(h, biggest[len-1]);
	free(biggest);
	while (h->sa->nb > l_nb(h->sa))
		ft_ra(h, 1);
}
