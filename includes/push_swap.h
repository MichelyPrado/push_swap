/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:01:48 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/18 10:01:50 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "defines.h"

struct s_stack
{
	int	*numbers;
	int	last;
};
typedef struct s_stack	t_stack;

// Error
int		ft_error(void);
int		ft_free_error(t_stack *a, t_stack *b);

// Main
int		ft_create_vector(int argc, char **args);
int		ft_alloc_stack(t_stack *a, t_stack *b, int args);
int		ft_define_index(t_stack *a, int args);

// Movements a
int		ft_swap_a(t_stack *a);
int		ft_rotate_a(t_stack *a);
int		ft_reverse_rotate_a(t_stack *a);
int		ft_push_a(t_stack *b, t_stack *a);

// Movements b
int		ft_swap_b(t_stack *b);
int		ft_rotate_b(t_stack *b);
int		ft_reverse_rotate_b(t_stack *b);
int		ft_push_b(t_stack *a, t_stack *b);

// Movements both
int		ft_swap_swap(t_stack *a, t_stack *b);
int		ft_rotate_rotate(t_stack *a, t_stack *b);
int		ft_reverse_rotate_rotate(t_stack *a, t_stack *b);

// Movements utils
int		ft_ret_bigger(t_stack *a);
int		ft_ret_pos_smaller(t_stack *a);
int		ft_ret_bigger_binary(t_stack *a);
int		ft_is_sorted(t_stack *a);

// Organizer
void	ft_checker(t_stack *a, t_stack *b, int numbers);
void	ft_sort_for_3(t_stack *a, t_stack *b);
void	ft_sort_for_5(t_stack *a, t_stack *b);
void	ft_sort_more_5(t_stack *a, t_stack *b, int nums_stack);
void	ft_exec_move(int move, t_stack *a, t_stack *b);

// Utils
int		ft_is_only_numbers(char **arg);
long	ft_atoi_plus(const char *nptr);
int		ft_check_repeat_num(t_stack *a);

#endif