/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:32:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/27 10:22:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	static t_data	data;
	static t_params	params;
	t_err			err;

	data.stage = INIT;
	err = ft_handle_input(&params, argc, argv, &data.meals);
	if (err != SUCCESS)
		return (ft_print_err_msg(err));
	err = ft_init_sim(&data, &params);
	if (err != SUCCESS)
		return (ft_cleanup(&data, err, params.num_philos));
	err = ft_start_sim(data.philos, &params, data.meals);
	if (err != SUCCESS)
		return (ft_cleanup(&data, err, params.num_philos));
	if (data.philos->status == DEAD)
		printf("💀 A Philosopher died\n");
	if (data.philos->status == FULL)
		printf("🫶  Every Philosopher is full ✨\n");
	ft_cleanup(&data, SUCCESS, params.num_philos);
}
