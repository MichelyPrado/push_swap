/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:10:58 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/19 13:16:13 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap_a(t_stack *a)
{
	int	aux;

	if (a->last <= 0)
	{
		return (1);
	}
	aux = a->numbers[0];
	a->numbers[0] = a->numbers[1];
	a->numbers[1] = aux;
	return (0);
}

int	ft_rotate_a(t_stack *a)
{
	int	aux_numbers;
	int	i;

	if (a->last <= 0)
	{
		return (1);
	}
	i = 0;
	aux_numbers = a->numbers[0];
	while (i < a->last)
	{
		a->numbers[i] = a->numbers[i + 1];
		i++;
	}
	a->numbers[i] = aux_numbers;
	return (0);
}

int	ft_reverse_rotate_a(t_stack *a)
{
	int	aux_numbers;
	int	i;

	if (a->last <= 0)
	{
		return (1);
	}
	i = a->last;
	aux_numbers = a->numbers[i];
	while (i > 0)
	{
		a->numbers[i] = a->numbers[i - 1];
		i--;
	}
	a->numbers[i] = aux_numbers;
	return (0);
}

int	ft_push_a(t_stack *b, t_stack *a)
{
	int	i;

	if (b->last < 0)
	{
		return (1);
	}
	i = a->last + 1;
	while (i > 0)
	{
		a->numbers[i] = a->numbers[i - 1];
		i--;
	}
	a->numbers[0] = b->numbers[0];
	while (i < b->last)
	{
		b->numbers[i] = b->numbers[i + 1];
		i++;
	}
	b->last = b->last - 1;
	a->last = a->last + 1;
	return (0);
}
