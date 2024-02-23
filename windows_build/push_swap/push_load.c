
#include "push_swap.h"

static void	check_double(t_stack *A)
{
	t_stack	*temp;
	t_stack	*fast_temp;

	temp = A;
	fast_temp = A->next;
	while (temp->next != NULL)
	{
		while (fast_temp->next != NULL)
		{
			fast_temp = fast_temp->next;
			if (fast_temp->content == temp->content)
			{
				printf("fast:%i | temp:%i\n", fast_temp->content, temp->content);
				error("List has doubles!");
			}
		}
		temp = temp->next;
	}
}

static void	load_all(t_stack **A, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		insert_node(A, new_node(ft_atoi(argv[i])));
		i++;
	}
}

static void	skip_delimiter(char *string, int *i)
{
	while (string[(*i)] < '0' || string[(*i)] > '9')
	{
		(*i)++;
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
			insert_node(A, new_node(num));
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
