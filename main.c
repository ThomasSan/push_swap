#include "push_swap.h"

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
	head->max = -2147483648;
	head->min = 2147483647;
	while (argv[++i])
	{
		if (check_digit(argv[i]) == -1)
			return (flush(head->stackA));
		head->stackA = push_back_stack(head->stackA, ft_atoi(argv[i]));
		head->min = ft_atoi(argv[i]) < head->min ? ft_atoi(argv[i]) : head->min;
		head->max = ft_atoi(argv[i]) > head->max ? ft_atoi(argv[i]) : head->max;
	}
	show_list(head);
	ft_pushB(head);
	ft_sa(head);
	rrA(head);
	rrA(head);
	ft_sa(head);
	rotateA(head);
	ft_pushA(head);
	show_list(head);
	printf("min : %d max : %d\n", head->min, head->max);
	return (0);
}

// dans error verifier le plus petit int