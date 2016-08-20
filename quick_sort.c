/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 15:27:13 by tsanzey           #+#    #+#             */
/*   Updated: 2016/08/20 15:27:15 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int			rightbigger(t_stack *head, int med)
{
	while (head)
	{
		if (head->nb < med)
			return (0);
		head = head->n;
	}
	return (1);
}

int			leftsmaller(t_stack *head, int med)
{
	while (head)
	{
		if (head->nb > med)
			return (0);
		head = head->n;
	}
	return (1);
}

int			get_new_med(t_stack *head)
{
	int	ret;
	int	len;
	int	index;
	int *arr;

	len = l_len(head);
	arr = fill_array2(head, len);
	arr = sort_array(arr, len);
	index = len % 2 == 0 ? len / 2 - 1 : len / 2;
	ret = arr[index];
	free(arr);
	return (ret);
}

void		q_sort2(t_shell *head)
{
	if (l_nb(head->sb) == head->med)
		ft_rrb(head, 1);
	head->med = get_new_med(head->sb);
	while (head->sb && !leftsmaller(head->sb, head->med))
	{
		// show_list(head);
		// printf("med->sort2 %d\n", head->med);
		if (ft_rev_sorted(head->sb) && !ft_sorted(head->sa))
		{
			if (l_nb(head->sa) == head->med)
				ft_rra(head, 1);
			break ;
		}
		if (l_nb(head->sb) > head->sb->nb)
			ft_rb(head, 1);
		else if (head->sb->nb < head->sb->n->nb)
			ft_sb(head, 1);
		else if (head->sb->nb > head->med)
		{
			ft_pa(head, 1);
			if (head->sa->nb > head->sa->n->nb)
				ft_sa(head, 1);
		}
		else if (head->sb->nb < head->med)
			ft_rb(head, 1);
		else
		{
			ft_pa(head, 1);
			if (!leftsmaller(head->sb, head->med))
				ft_ra(head, 1);
		}
		if (l_len(head->sb) > 1 && leftsmaller(head->sb, head->med))
		{
			if (l_nb(head->sa) == head->med)
				ft_rra(head, 1);
			head->med = get_new_med(head->sb);
		}
	}
	if (l_len(head->sb) == 1)
		ft_pa(head, 1);
}

void		wat_todo(t_shell *head)
{
	if (l_nb(head->sb) > head->sb->nb && l_nb(head->sb) != head->med)
	{
		if (head->sa->nb > head->med)
			ft_rr(head, 1);
		else
			ft_rb(head, 1);
	}
	if (l_len(head->sb) > 1 && head->sb->nb < head->sb->n->nb)
	{
		if (head->sa->nb > head->sa->n->nb)
			ft_ss(head, 1);
		else
			ft_sb(head, 1);
	}
}

void		q_sort(t_shell *head)
{
	head->med = get_new_med(head->sa);
	while (head->sa && !rightbigger(head->sa, head->med))
	{
		// show_list(head);
		// printf("med->sort %d\n", head->med);
		// if (head->sa->nb > head->sa->n->nb)
		// 	ft_sa(head, 1);
		if (ft_sorted(head->sa) && rightbigger(head->sa, head->med))
			q_sort2(head) ;
		if (head->sa->nb > head->med)
				ft_ra(head, 1);
		else if (head->sa->nb < head->med)
		{
			ft_pb(head, 1);
			wat_todo(head);
		}
		else if (!rightbigger(head->sa, head->med))
		{
			ft_pb(head, 1);
			ft_rb(head, 1);
		}
		if (l_len(head->sa) == 2 && !ft_sorted(head->sa))
			ft_sa(head, 1);
		if (!ft_sorted(head->sa) && rightbigger(head->sa, head->med))
		{
			if (l_nb(head->sb) == head->med)
				ft_rrb(head, 1);
			if (ft_rev_sorted(head->sb))
				head->med = get_new_med(head->sa);
			else
				q_sort2(head);
		}
	}
	q_sort2(head);
}

// void		q_sort2(t_shell *head)
// {
// 	if (head->sb && l_nb(head->sb) == head->med)
// 		ft_rrb(head, 1);
// 	head->med = get_new_med(head->sb);
// 	while (head->sb && !leftsmaller(head->sb, head->med))
// 	{
// 		show_list(head);
// 		printf("med->sort2 %d\n", head->med);
// 		if (l_nb(head->sb) > head->sb->nb)
// 			ft_rb(head, 1);
// 		else if (head->sb->nb < head->sb->n->nb)
// 			ft_sb(head, 1);
// 		else if (head->sb->nb > head->med)
// 		{
// 			ft_pa(head, 1);
// 			if (head->sa->nb > head->sa->n->nb)
// 				ft_sa(head, 1);
// 		}
// 		else if (head->sb->nb < head->med)
// 			ft_rb(head, 1);
// 		else
// 			ft_pa(head, 1);
// 		if (l_len(head->sb) > 1 && leftsmaller(head->sb, head->med))
// 			head->med = get_new_med(head->sb);
// 	}
// 	if (l_len(head->sb) == 1)
// 		ft_pa(head, 1);
// }

// void		q_sort(t_shell *head)
// {
// 	head->med = get_new_med(head->sa);
// 	while (head->sa && !rightbigger(head->sa, head->med))
// 	{
// 		show_list(head);
// 		printf("med->sort %d\n", head->med);
// 		if (ft_sorted(head->sa))
// 			break ;
// 		if (head->sa->nb > head->med)
// 				ft_ra(head, 1);
// 		else if (head->sa->nb < head->med)
// 		{
// 			ft_pb(head, 1);
// 			if (l_nb(head->sb) > head->sb->nb && l_nb(head->sb) != head->med)
// 				ft_rb(head, 1);
// 			if (l_len(head->sb) > 1 && head->sb->nb < head->sb->n->nb)
// 			{
// 				if (head->sa->nb > head->sa->n->nb)
// 					ft_ss(head, 1);
// 				else
// 					ft_sb(head, 1);
// 			}
// 		}
// 		else if (!rightbigger(head->sa, head->med))
// 		{
// 			ft_pb(head, 1);
// 			ft_rb(head, 1);
// 		}
// 		if (l_len(head->sa) == 2 && !ft_sorted(head->sa))
// 			ft_sa(head, 1);
// 		if (!ft_sorted(head->sa) && rightbigger(head->sa, head->med))
// 		{
// 			if (l_nb(head->sb) == head->med)
// 				ft_rrb(head, 1);
// 			head->med = get_new_med(head->sa);
// 		}
// 	}
// 	q_sort2(head);
// }