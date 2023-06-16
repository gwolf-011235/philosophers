/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:11:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/16 14:40:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

t_err	ft_m_destroy_forks_in_use(t_fork *forks, int32_t num_philos)
{
	int32_t	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_destroy(&forks[i].m_in_use) != 0)
			return (ERR_MUTEX_DESTROY);
		i++;
	}
	return (SUCCESS);
}

t_err	ft_m_destroy_philo_last_meal(t_philo *philos, int32_t num_philos)
{
	int32_t	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_destroy(&philos[i].m_last_meal) != 0)
			return (ERR_MUTEX_DESTROY);
		i++;
	}
	return (SUCCESS);
}

t_err	ft_m_destroy_philo_meals_ate(t_philo *philos, int32_t num_philos)
{
	int32_t	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_destroy(&philos[i].m_meals_ate) != 0)
			return (ERR_MUTEX_DESTROY);
		i++;
	}
	return (SUCCESS);
}

t_err	ft_m_destroy_philo_stop_sim(t_philo *philos, int32_t num_philos)
{
	int32_t	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_destroy(&philos[i].m_status) != 0)
			return (ERR_MUTEX_DESTROY);
		i++;
	}
	return (SUCCESS);
}
