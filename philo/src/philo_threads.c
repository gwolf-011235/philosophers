/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:11:08 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/12 23:45:09 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_threads.h"

t_err	ft_spin_threads(t_data *data, t_philo *philos, t_params *params)
{
	int32_t		i;

	params->start_time = ft_timestamp_in_ms();
	if (params->start_time == -1)
		return (ERR_TIME);
	i = 0;
	while (i < params->num_philos)
	{
		pthread_create(&philos[i].thread_id, NULL, ft_philo_life, &philos[i]);
		i++;
	}
	pthread_create(&data->check_alive, NULL, ft_check_health, philos);

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
