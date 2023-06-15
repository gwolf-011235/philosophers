/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:45:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/15 17:29:30 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

/**
 * @brief Prints log of state change of a philosopher. Mutex protected.
 *
 * @param philo Philo who prints.
 * @param index	Type of msg: FORK, EAT, SLEEP, THINK, DIED
 */
void	ft_print(t_philo *philo, t_msg index)
{
	static const char	*msg[5] = {
	[FORK] = "has taken a fork",
	[EAT] = "is eating",
	[SLEEP] = "is sleeping",
	[THINK] = "is thinking",
	[DIED] = "died"
	};
	int64_t				curr_timestamp;

	pthread_mutex_lock(philo->m_print);
	if (!*philo->stop_sim)
	{
		curr_timestamp = ft_timestamp_in_ms() - philo->params->start_time;
		printf("%ld\t%d %s\n", curr_timestamp, philo->id, msg[index]);
	}
	if (index == DIED)
		*philo->stop_sim = true;
	pthread_mutex_unlock(philo->m_print);
}

t_err	ft_get_philo_status(t_philo *philo, t_status *status)
{
	pthread_mutex_lock(&philo->m_status);
	*status = philo->status;
	pthread_mutex_unlock(&philo->m_status);
	return (SUCCESS);
}

t_err	ft_set_philo_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->m_status);
	philo->status = status;
	pthread_mutex_unlock(&philo->m_status);
	return (SUCCESS);
}

t_err	ft_update_philo_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_last_meal);
	philo->last_meal = ft_timestamp_in_ms();
	pthread_mutex_unlock(&philo->m_last_meal);
	return (SUCCESS);
}

t_err	ft_update_philo_meals_ate(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_meals_ate);
	philo->meals_ate++;
	pthread_mutex_unlock(&philo->m_meals_ate);
	return (SUCCESS);
}
