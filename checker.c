#include "get_next_line.h"
#include "checker.h"
#include "push_swap.h"
#include <unistd.h>

int		get_index(char *s)
{
	int 				i;
	static const char	*cmd[] = {"sa", "sb", "ss", "pb", "pa",
	"ra", "rb", "rr", "rra", "rrb", "rrr"};

	i = 0;
	while(i < 11)
	{
		if (ft_strcmp(cmd[i], s) == 0)
			break ;
		i++;
	}
	return i;
}

void	ft_check(s_shell *head, char *s)
{
	int		(*fun_array[11])(s_shell *head);
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
		fun_array[index](head);
	else
		ft_putendl_fd("Error", 2);
}

int		main(int argc, char *argv[])
{
	s_shell		*head;
	int			i;

	i = 0;
	if (argc == 2)
		ft_strsplit(argv[1], ' ');
	if (argc == 1 || !(head = (s_shell*)malloc(sizeof(s_shell*))))
		return (0);
	head->stackA = NULL;
	head->stackB = NULL;
	while (argv[++i])
	{
		if (check_digit(argv[i]) == -1)
			return (flush(head->stackA, 0));
		head->stackA = push_back_stack2(head->stackA, ft_atoi(argv[i]));
	}
	char *buff = NULL;
	while (get_next_line(0, &buff))
		ft_check(head, buff);
	if (ft_sorted(head->stackA) && stack_list_len(head->stackB) == 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free_lst(head);
	return (0);
}