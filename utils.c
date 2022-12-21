/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-p <msilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:25:56 by msilva-p          #+#    #+#             */
/*   Updated: 2022/12/20 21:46:44 by msilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_trim(char *trim)
{
	free(trim);
	return (1);
}

int	ft_is_only_numbers(char **argv)
{
	int		column;
	char	*trim;

	while (argv[0] != NULL)
	{
		trim = ft_strtrim(argv[0], " ");
		if (!trim || !*trim)
			return (free_trim(trim));
		column = 0;
		while (trim[column] != '\0')
		{
			if ((ft_isdigit(trim[column]) == 0
					&& ((trim[column] != '-' && trim[column] != '+')
						|| column != 0)) || ((trim[column] == '-' || \
						trim[column] == '+') && trim[column + 1] == '\0'))
				return (free_trim(trim));
			column++;
		}
		free(trim);
		argv++;
	}
	return (0);
}

long	ft_atoi_plus(const char *nptr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		if (result * sign < INT_MIN || result * sign > INT_MAX)
		{
			return (42000000000);
		}
		nptr++;
	}
	return (result * sign);
}

int	ft_check_repeat_num(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->last)
	{
		j = i + 1;
		while (j <= a->last)
		{
			if (a->numbers[j] == a->numbers[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
