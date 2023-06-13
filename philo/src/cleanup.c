/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:29:45 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/13 10:26:29 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "teardown.h"

t_err	ft_cleanup(t_data *data, t_err err, int32_t num_philos)
{
	if (data->stage == POST_MUTEX_PHILO)
	{
		if (ft_m_destroy_philo_stop_sim(data->philos, num_philos) != SUCCESS)
			return (ft_print_err_msg(PANIC));
		if (ft_m_destroy_philo_meals_ate(data->philos, num_philos) != SUCCESS)
			return (ft_print_err_msg(PANIC));
		if (ft_m_destroy_philo_last_meal(data->philos, num_philos) != SUCCESS)
			return (ft_print_err_msg(PANIC));
	}
	if (data->stage >= POST_MUTEX_FORK)
	{
		if (ft_m_destroy_forks_in_use(data->forks, num_philos) != SUCCESS)
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
	printf("🧹 All cleaned up.\n");
	return (ft_print_err_msg(err));
}
