/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:05:05 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/18 10:05:06 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap_b(t_stack *b)
{
	int	aux;

	if (b->last <= 0)
	{
		return (1);
	}
	aux = b->numbers[0];
	b->numbers[0] = b->numbers[1];
	b->numbers[1] = aux;
	return (0);
}

int	ft_rotate_b(t_stack *b)
{
	int	aux_numbers;
	int	i;

	if (b->last <= 0)
	{
		return (1);
	}
	i = 0;
	aux_numbers = b->numbers[0];
	while (i < b->last)
	{
		b->numbers[i] = b->numbers[i + 1];
		i++;
	}
	b->numbers[i] = aux_numbers;
	return (0);
}

int	ft_reverse_rotate_b(t_stack *b)
{
	int	aux_numbers;
	int	i;

	if (b->last <= 0)
	{
		return (1);
	}
	i = b->last;
	aux_numbers = b->numbers[i];
	while (i > 0)
	{
		b->numbers[i] = b->numbers[i - 1];
		i--;
	}
	b->numbers[i] = aux_numbers;
	return (0);
}

int	ft_push_b(t_stack *a, t_stack *b)
{
	int	i;

	if (a->last < 0)
	{
		return (1);
	}
	i = b->last + 1;
	while (i > 0)
	{
		b->numbers[i] = b->numbers[i - 1];
		i--;
	}
	b->numbers[0] = a->numbers[0];
	while (i < a->last)
	{
		a->numbers[i] = a->numbers[i + 1];
		i++;
	}
	a->last = a->last - 1;
	b->last = b->last + 1;
	return (0);
}
