/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:04:13 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/18 10:04:15 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd ("Error\n", 2);
	return (1);
}

int	ft_free_error(t_stack *a, t_stack *b)
{
	free (a->numbers);
	free (b->numbers);
	return (ft_error());
}
