/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitoring.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:32:44 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/16 14:38:04 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

t_err	ft_set_status_all(t_philo *philos, t_status status)
{
	int32_t	i;

	i = 0;
	while (i < philos->params->num_philos)
	{
		ft_set_philo_status(&philos[i], status);
		i++;
	}
	return (SUCCESS);
}

bool	ft_is_dead(t_philo *philo)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(&philo->m_last_meal);
	if (ft_timestamp_in_ms() - philo->last_meal > philo->params->time_to_die)
		ret = true;
	pthread_mutex_unlock(&philo->m_last_meal);
	if (ret)
	{
		pthread_mutex_lock(&philo->m_status);
		if (philo->status < DEAD)
		{
			philo->status = DEAD;
			ft_print(philo, DIED);
		}
		pthread_mutex_unlock(&philo->m_status);
	}
	return (ret);
}

bool	ft_is_full(t_philo *philo)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(&philo->m_meals_ate);
	if (philo->meals_ate >= philo->params->times_to_eat)
		ret = true;
	pthread_mutex_unlock(&philo->m_meals_ate);
	if (ret)
	{
		pthread_mutex_lock(&philo->m_status);
		if (philo->status == ACTIVE)
			philo->status = FULL;
		pthread_mutex_unlock(&philo->m_status);
	}
	return (ret);
}

t_err	ft_dead_or_full(t_philo *philos, bool *alive, bool *hungry, bool meals)
{
	int32_t		i;
	int32_t		philos_fed;

	i = 0;
	philos_fed = 0;
	while (i < philos->params->num_philos)
	{
		if (ft_is_dead(&philos[i]) == true)
		{
			*alive = false;
			break ;
		}
		if (meals && ft_is_full(&philos[i]) == true)
			philos_fed++;
		i++;
	}
	if (philos_fed == philos->params->num_philos)
		*hungry = false;
	return (SUCCESS);
}

t_err	ft_monitoring(t_philo *philos, bool meals)
{
	t_err	err;
	bool	alive;
	bool	hungry;

	alive = true;
	hungry = true;
	while (alive && hungry)
	{
		err = ft_dead_or_full(philos, &alive, &hungry, meals);
		if (err != SUCCESS)
			return (err);
	}
	if (!alive)
		ft_set_status_all(philos, DEAD);
	if (!hungry)
		ft_set_status_all(philos, FULL_STOP);
	return (SUCCESS);
}
