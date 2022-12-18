/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:04:47 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/18 10:04:49 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	only_numbers;

	argv++;
	if (argv[0] == NULL)
		return (1);
	only_numbers = ft_is_only_numbers(argv);
	if (only_numbers == 1)
		return (ft_error());
	ft_create_vector(--argc, argv);
	return (0);
}

int	ft_create_vector(int argc, char **args)
{
	t_stack	a;
	t_stack	b;
	int		i;
	long	atoi_plus;

	if (ft_alloc_stack(&a, &b, argc) == 1)
		return (1);
	a.last = argc - 1;
	b.last = -1;
	i = 0;
	while (args[i] != NULL)
	{
		atoi_plus = ft_atoi_plus(args[i]);
		if (atoi_plus == 42000000000)
			return (ft_free_error(&a, &b));
		a.numbers[i] = atoi_plus;
		i++;
	}
	if (ft_define_index(&a, argc) || ft_check_repeat_num(&a) == 1)
		return (ft_free_error(&a, &b));
	ft_checker(&a, &b, a.last);
	free(a.numbers);
	free(b.numbers);
	return (0);
}

int	ft_alloc_stack(t_stack *a, t_stack *b, int args)
{
	if (args == 0)
		return (1);
	a->numbers = (int *) malloc(args * sizeof(int));
	if (a->numbers == NULL)
		return (ft_error());
	b->numbers = (int *) malloc(args * sizeof(int));
	if (b->numbers == NULL)
	{
		free(a->numbers);
		return (ft_error());
	}
	return (0);
}

int	ft_define_index(t_stack *a, int args)
{
	int	first_index;
	int	second_index;
	int	*indexes;

	first_index = 0;
	indexes = (int *) malloc(args * sizeof(int));
	if (!indexes)
		return (1);
	while (first_index < args)
	{
		indexes[first_index] = 0;
		second_index = 0;
		while (second_index < args)
		{
			if (a->numbers[first_index] > a->numbers[second_index])
			{
				indexes[first_index] += 1;
			}
			second_index++;
		}
		first_index++;
	}
	free(a->numbers);
	a->numbers = indexes;
	return (0);
}
