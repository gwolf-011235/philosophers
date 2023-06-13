/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:11:08 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/13 12:28:36y gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_threads.h"

t_err	ft_set_startup_time(t_philo *philos, t_params *params)
{
	int32_t	i;

	params->start_time = ft_timestamp_in_ms();
	if (params->start_time == -1)
		return (ERR_TIME);
	i = 0;
	while (i < params->num_philos)
	{
		philos[i].last_meal = ft_timestamp_in_ms();
		i++;
	}
	return (SUCCESS);
}

t_err	ft_monitoring_threads(t_data *data, t_philo *philos, t_params *params)
{
	if (params->num_philos > 1
		&& pthread_create(&data->check_life, NULL, ft_check_life, philos) != 0)
	{
		printf("⚠️  Could not create monitor thread check_life\n");
		return (ft_stop_and_join(data, ERR_THREAD_CREATE, params->num_philos));
	}
	if (params->num_philos > 1 && data->meals
		&& pthread_create(&data->check_full, NULL, ft_check_full, philos) != 0)
	{
		printf("⚠️  Could not create monitor thread check_full\n");
		pthread_join(data->check_life, NULL);
		return (ft_stop_and_join(data, ERR_THREAD_CREATE, params->num_philos));
	}
	return (SUCCESS);
}

t_err	ft_spin_threads(t_data *data, t_philo *philos, t_params *params)
{
	int32_t		i;

	ft_set_startup_time(philos, params);
	i = 0;
	while (i < params->num_philos)
	{
		if (pthread_create(&philos[i].thread_id, NULL,
				ft_philo_life, &philos[i]) != 0)
		{
			printf("⚠️  Could not create philo thread with ID %d\n", i);
			return (ft_stop_and_join(data, ERR_THREAD_CREATE, i));
		}
		i++;
	}
	if (ft_monitoring_threads(data, philos, params) != SUCCESS)
		return (ERR_THREAD_CREATE);
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
	if (params->num_philos > 1)
		pthread_join(data->check_life, NULL);
	if (params->num_philos > 1 && data->meals)
		pthread_join(data->check_full, NULL);
	return (SUCCESS);
}

t_err	ft_stop_and_join(t_data *data, t_err err, int32_t num_philos)
{
	ft_stop_all(data->philos);
	num_philos--;
	while (num_philos >= 0)
	{
		pthread_join(data->philos[num_philos].thread_id, NULL);
		num_philos--;
	}
	return (err);
}
