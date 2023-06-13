/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:29:45 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/13 00:31:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "teardown.h"

t_err	ft_cleanup(t_data *data, t_err err, int32_t num_philos)
{
	if (data->stage == POST_MUTEX_PHILO)
	{
		err = ft_m_destroy_philo_status(data->philos, num_philos);
		if (err != SUCCESS)
			return (ft_print_err_msg(PANIC));
		err = ft_m_destroy_philo_last_meal(data->philos, num_philos);
		if (err != SUCCESS)
			return (ft_print_err_msg(PANIC));
	}
	if (data->stage >= POST_MUTEX_FORK)
	{
		err = ft_m_destroy_forks_in_use(data->forks, num_philos);
		if (err != SUCCESS)
			return (ft_print_err_msg(PANIC));
	}
	if (data->stage >= POST_MUTEX_DATA)
		if (pthread_mutex_destroy(&data->m_print) != 0)
			return (ft_print_err_msg(PANIC));
	if (data->stage >= POST_MALLOC)
	{
		free(data->philos);
		free(data->forks);
	}
	return (ft_print_err_msg(err));
}