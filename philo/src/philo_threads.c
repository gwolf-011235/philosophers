/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:11:08 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/13 08:35:20 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_threads.h"

t_err	ft_spin_threads(t_data *data, t_philo *philos, t_params *params)
{
	int32_t		i;
	t_err		err;

	err = SUCCESS;
	params->start_time = ft_timestamp_in_ms();
	if (params->start_time == -1)
		return (ERR_TIME);
	i = 0;
	while (i < params->num_philos)
	{
		if (pthread_create(&philos[i].thread_id, NULL,
				ft_philo_life, &philos[i]) != 0)
		{
			printf("Could not create philo thread with ID %d\n", i);
			err = ERR_THREAD_CREATE;
			break ;
		}
		i++;
	}
	if (err == ERR_THREAD_CREATE)
	{
		ft_stop_all(philos);
		return (err);
	}
	if (pthread_create(&data->check_alive, NULL, ft_check_health, philos) != 0)
	{
		printf("Could not create check_health thread\n");
		return (ERR_THREAD_CREATE);
	}
	return (SUCCESS);
}

t_err	ft_join_threads(t_data *data, t_philo *philos, t_params *params)
{
	int32_t	i;

	i = 0;
	while (i < params->num_philos)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
	pthread_join(data->check_alive, NULL);
	return (SUCCESS);
}
