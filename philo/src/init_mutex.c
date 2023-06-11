/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:27:54 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/11 19:27:19 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include "return_codes.h"

/**
 * @brief Init mutex m_in_use in forks array.
 *
 * @param forks Forks array.
 * @param num_philos Number of philos.
 * @return t_err SUCCESS, ERR_MUTEX_INIT
 */
t_err	ft_m_init_forks_in_use(t_fork *forks, int32_t num_philos)
{
	int32_t	i;
	bool	init_fail;

	i = 0;
	init_fail = false;
	while (i < num_philos)
	{
		if (pthread_mutex_init(&forks[i].m_in_use, NULL) != 0)
		{
			init_fail = true;
			break ;
		}
		i++;
	}
	if (init_fail)
	{
		while (--i >= 0)
			pthread_mutex_destroy(&forks[i].m_in_use);
		return (ERR_MUTEX_INIT);
	}
	return (SUCCESS);
}

/**
 * @brief Init mutex m_last_meal in philos array.
 *
 * @param philos Philos array.
 * @param num_philos Numer of philos.
 * @return t_err SUCCESS, ERR_MUTEX_INIT
 */
t_err	ft_m_init_philos_last_meal(t_philo *philos, int32_t num_philos)
{
	int32_t	i;
	bool	init_fail;

	i = 0;
	init_fail = false;
	while (i < num_philos)
	{
		if (pthread_mutex_init(&philos[i].m_last_meal, NULL) != 0)
		{
			init_fail = true;
			break ;
		}
		i++;
	}
	if (init_fail)
	{
		while (--i >= 0)
			pthread_mutex_destroy(&philos[i].m_last_meal);
		return (ERR_MUTEX_INIT);
	}
	return (SUCCESS);
}

/**
 * @brief Init mutex m_stop_sim in philos array.
 *
 * @param philos Philos array.
 * @param num_philos Number of philos.
 * @return t_err SUCCESS, ERR_MUTEX_INIT
 */
t_err	ft_m_init_philos_stop_sim(t_philo *philos, int32_t num_philos)
{
	int32_t	i;
	bool	init_fail;

	i = 0;
	init_fail = false;
	while (i < num_philos)
	{
		if (pthread_mutex_init(&philos[i].m_stop_sim, NULL) != 0)
		{
			init_fail = true;
			break ;
		}
		i++;
	}
	if (init_fail)
	{
		while (--i >= 0)
			pthread_mutex_destroy(&philos[i].m_stop_sim);
		return (ERR_MUTEX_INIT);
	}
	return (SUCCESS);
}
