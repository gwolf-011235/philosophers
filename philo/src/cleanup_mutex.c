/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:11:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/16 14:39:13 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanu
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
p.h"

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
