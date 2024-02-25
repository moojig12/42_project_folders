#include "push_swap.h"

static void	load_all(t_stack **A, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		append_node(A, ft_atoi(argv[i]));
		i++;
	}
}

static void load_array(t_stack **A, char *string)
{
	int	num;
	int	i;

	i = 0;
	skip_delimiter(string, &i);
	while (string[i])
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			num = (ft_atoi(&string[i]));
			while (string[i] >= '0' && string[i] <= '9')
				i++;
		}
		else
		{
			append_node(A, num);
			num = 0;
			skip_delimiter(string, &i);
		}
	}
	if (num != 0)
		insert_node(A, new_node(num));
	return ;
}

void	load_list(char **argv, int mode, t_stack **A)
{
	if (mode == 1)
		load_array(A, argv[1]);
	else if (mode == 0)
		load_all(A, argv);
	// check if there are doubles
	check_double(*A);
}