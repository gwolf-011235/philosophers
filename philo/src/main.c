/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:32:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/15 13:01:54 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	static t_data	data;
	static t_params	params;
	t_err			err;

	data.stage = INIT;
	err = ft_check_args(argc, argv);
	if (err != SUCCESS)
		return (ft_print_err_msg(err));
	err = ft_set_params(&params, argc, argv, &data.meals);
	if (err != SUCCESS)
		return (ft_print_err_msg(err));
	err = ft_setup_vars(&data, &params);
	if (err != SUCCESS)
		return (ft_cleanup(&data, err, params.num_philos));
	err = ft_spin_threads(&data, data.philos, &params);
	if (err != SUCCESS)
		return (ft_cleanup(&data, err, params.num_philos));
	err = ft_join_threads(&data, data.philos, &params);
	if (err != SUCCESS)
		return (ft_cleanup(&data, err, params.num_philos));
	ft_cleanup(&data, SUCCESS, params.num_philos);
}
