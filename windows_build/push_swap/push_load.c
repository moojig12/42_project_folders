
#include "push_swap.h"


static void	check_double(t_stack *A)
{
	t_stack	*temp;
	t_stack	*fast_temp;

	temp = A;
	fast_temp = A;
	while (temp)
	{
		while (fast_temp)
		{
			if (fast_temp->value == temp->value)
				error("List has doubles!");
			fast_temp = fast_temp->next;
		}
		fast_temp = A;
		temp = temp->next;
	}
}

static void	load_all(t_stack **A, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		add_node(A, ft_atoi(argv[i]));
		i++;
	}
}

static void load_array(t_stack **A, char *string)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (string[i])
	{
		while (string[i] > '0' && string[i] < '9')
		{
			size++;
			i++;
		}
	}
}

void	load_list(char **argv, int mode, t_stack **A)
{
	if (mode == 0)
		load_array(A, argv[1]);
	else if (mode == 1)
		load_all(A, argv);
	// check if there are doubles
	check_double(*A);
}
