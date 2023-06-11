/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:08:56 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/11 09:16:49 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

t_err	ft_check_args(int argc, char **argv)
{
	uint32_t	i;

	if (argc < 5 || argc > 6)
	{
		printf("⚠️  Expected 4 [5] args, got: %d\n", argc - 1);
		return (ERR_NUMARGS);
	}
	while (argc-- > 1)
	{
		i = 0;
		while (argv[argc][i])
		{
			if (ft_isdigit(argv[argc][i]) != SUCCESS)
			{
				printf("⚠️  Not digit: %s (%d)\n", argv[argc], argc);
				return (ERR_NOTDIGIT);
			}
			i++;
		}
	}
	return (SUCCESS);
}

t_err	ft_set_params(t_params *params, int argc, char **argv)
{
	params->num_philos = ft_mini_atoi(argv[1]);
	params->time_to_die = ft_mini_atoi(argv[2]);
	params->time_to_eat = ft_mini_atoi(argv[3]);
	params->time_to_sleep = ft_mini_atoi(argv[4]);
	if (argc == 6)
		params->times_to_eat = ft_mini_atoi(argv[5]);
	if (params->num_philos < 0
		|| params->time_to_die < 0
		|| params->time_to_eat < 0
		|| params->time_to_sleep < 0
		|| (argc == 6 && params->times_to_eat < 0))
		return (ERR_OVERFLOW);
	if (params->num_philos == 0
		|| (argc == 6 && params->times_to_eat == 0))
		return (ERR_ISZERO);
	return (SUCCESS);
}
