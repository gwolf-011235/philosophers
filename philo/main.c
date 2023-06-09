/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:32:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/09 11:50:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	main(int argc, char *argv[])
{
	static t_params	params;
	t_err			err;

	err = ft_check_args(argc, argv);
	if (err != SUCCESS)
		return (ft_print_usage(argv[0], err));
	err = ft_set_params(&params, argc, argv);
	if (err != SUCCESS)
		return (ft_print_usage(argv[0], err));
	printf("This is params:\n%d\n%d\n%d\n%d\n%d\n", params.num_philos, params.time_to_die, params.time_to_eat, params.time_to_sleep, params.times_to_eat);
}
