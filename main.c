#include "push_swap.h"

int		main(int argc, char **argv)
{
	s_shell		*head;
	int			i;

	i = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
		ft_strsplit(argv[1], ' ');
	if (!(head = (s_shell*)malloc(sizeof(s_shell*))))
		return (0);
	head->stackA = NULL;
	head->stackB = NULL;
	while (argv[++i])
	{
		if (check_digit(argv[i]) == -1)
			return (flush(head->stackA, 0));
		head->stackA = push_back_stack2(head->stackA, ft_atoi(argv[i]));
		head->min = ft_atoi(argv[i]) < head->min ? ft_atoi(argv[i]) : head->min;
		head->max = ft_atoi(argv[i]) > head->max ? ft_atoi(argv[i]) : head->max;
	}
	while (ft_sorted(head->stackA) == 0)
		push_swap(head);
	free_lst(head);
	return (0);
}
