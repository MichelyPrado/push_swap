/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:06:16 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/18 10:06:16 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker(t_stack *a, t_stack *b, int numbers)
{
	if (ft_is_sorted(a))
		return ;
	if (numbers < 3)
		ft_sort_for_3(a, b);
	else if (numbers < 5)
		ft_sort_for_5(a, b);
	else
		ft_sort_more_5(a, b, a->last);
}

void	ft_sort_for_3(t_stack *a, t_stack *b)
{
	if (a->last < 1)
		return ;
	if (a->last == 1)
	{
		if (a->numbers[0] > a->numbers[1])
			ft_exec_move(SA, a, b);
	}
	else if (a->numbers[0] > a->numbers[1] && a->numbers[0] > a->numbers[2])
	{
		ft_exec_move(RA, a, b);
		if (a->numbers[0] > a->numbers[1])
			ft_exec_move(SA, a, b);
	}
	else if (a->numbers[1] > a->numbers[0] && a->numbers[1] > a->numbers[2])
	{
		ft_exec_move(RRA, a, b);
		if (a->numbers[0] > a->numbers[1])
			ft_exec_move(SA, a, b);
	}
	else if (a->numbers[2] > a->numbers[0] && a->numbers[2] > a->numbers[1])
	{
		if (a->numbers[0] > a->numbers[1])
			ft_exec_move(SA, a, b);
	}
}

void	ft_sort_for_5(t_stack *a, t_stack *b)
{
	int	small_pos;

	while (a->last >= 3)
	{
		small_pos = ft_ret_pos_smaller(a);
		if (small_pos == 0)
			ft_exec_move(PB, a, b);
		else if (small_pos == 1)
			ft_exec_move(SA, a, b);
		else if (small_pos == 2)
			ft_exec_move(RA, a, b);
		else if (small_pos == 3)
			ft_exec_move(RRA, a, b);
		else if (small_pos == 4)
			ft_exec_move(RRA, a, b);
	}
	ft_sort_for_3(a, b);
	while (b->last > -1)
		ft_exec_move(PA, a, b);
}

void	ft_sort_more_5(t_stack *a, t_stack *b, int nums_stack)
{
	int	qtd_dig_binary;
	int	i;
	int	j;

	qtd_dig_binary = ft_ret_bigger_binary(a);
	i = 0;
	while (i < qtd_dig_binary)
	{
		j = 0;
		while (j <= nums_stack)
		{
			if (a->numbers[0] >> i & 1)
			{
				ft_exec_move(RA, a, b);
			}
			else
			{
				ft_exec_move(PB, a, b);
			}
			j++;
		}
		while (b->last > -1)
			ft_exec_move(PA, a, b);
		i++;
	}
}

void	ft_exec_move(int move, t_stack *a, t_stack *b)
{
	if (move == PA && ft_push_a(b, a) == 0)
		ft_printf("pa\n");
	else if (move == PB && ft_push_b(a, b) == 0)
		ft_printf("pb\n");
	else if (move == SA && ft_swap_a(a) == 0)
		ft_printf("sa\n");
	else if (move == SB && ft_swap_b(b) == 0)
		ft_printf("sb\n");
	else if (move == RA && ft_rotate_a(a) == 0)
		ft_printf("ra\n");
	else if (move == RB && ft_rotate_b(b) == 0)
		ft_printf("rb\n");
	else if (move == RRA && ft_reverse_rotate_a(a) == 0)
		ft_printf("rra\n");
	else if (move == RRB && ft_reverse_rotate_b(b) == 0)
		ft_printf("rrb\n");
	else if (move == SS && ft_swap_swap(a, b) == 0)
		ft_printf("ss\n");
	else if (move == RR && ft_rotate_rotate(a, b) == 0)
		ft_printf("rr\n");
	else if (move == RRR && ft_reverse_rotate_rotate(a, b) == 0)
		ft_printf("rrr\n");
}
