
int			nb_toget(t_stack *lst, int med)
{
	int i;

	i = 0;
	while (lst)
	{
		if (lst->nb <= med)
			i++;
		lst = lst->n;
	}
	return (i);
}

int			where_to(t_stack *lst, int med)
{
	int	i;
	int	ret;

	i = 0;
	while (lst)
	{
		if (lst->nb <= med)
			ret = i;
		lst = lst->n;
		i++;
	}
	return (ret);
}

void		fast_to_nb(t_shell *head)
{
	int	rotation;
	int	len;
	int middle;

	len = l_len(head->sa);
	middle = len / 2;
	if (len - where_to(head->sa, head->med) > middle)
		rotation = 1;
	else
		rotation = 0;
	while (where_to(head->sa, head->med) != 0)
	{
		if (rotation)
			ft_rra(head, 1);
		else
			ft_ra(head, 1);
	}
}