/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:08:56 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/08 18:36:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_check_args(int argc, char **argv)
{
	uint32_t	i;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments. Expected 4/5, got: %d\n", argc);
		return (ERROR);
	}
	while (argc-- > 1)
	{
		i = 0;
		while (argv[argc][i])
		{
			if (!ft_isdigit(argv[argc][i]))
			{
				printf("Wrong type of argument: %s (%d)\n", argv[argc], argc);
				return (ERROR);
			}
			i++;
		}
	}
	return (0);
}

int	ft_print_usage(char *prog_name)
{
	printf("\nusage: %s number_of_philosophers time_to_die time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n", prog_name);
	return (ERROR);
}
