/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:32:44 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/13 12:29:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

t_err	ft_stop_all(t_philo *philos)
{
	int32_t	i;

	i = 0;
	while (i < philos->params->num_philos)
	{
		ft_set_philo_stop_sim(&philos[i]);
		i++;
	}
	return (SUCCESS);
}

bool	ft_is_dead(t_philo *philo)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(&philo->m_last_meal);
	if (ft_timestamp_in_ms() - philo->last_meal >= philo->params->time_to_die)
		ret = true;
	pthread_mutex_unlock(&philo->m_last_meal);
	if (ret)
	{
		pthread_mutex_lock(&philo->m_stop_sim);
		if (philo->stop_sim == false)
		{
			philo->stop_sim = true;
			ft_print(philo, DIED);
		}
		pthread_mutex_unlock(&philo->m_stop_sim);
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
		pthread_mutex_lock(&philo->m_stop_sim);
		philo->stop_sim = true;
		pthread_mutex_unlock(&philo->m_stop_sim);
	}
	return (ret);
}

void	*ft_check_life(void *arg)
{
	int32_t	i;
	bool	all_well;
	t_philo	*philos;

	all_well = true;
	philos = (t_philo *)arg;
	while (all_well)
	{
		i = 0;
		while (i < philos->params->num_philos)
		{
			if (ft_is_dead(&philos[i]) == true)
				all_well = false;
			i++;
		}
	}
	ft_stop_all(philos);
	return (NULL);
}

void	*ft_check_full(void *arg)
{
	int32_t	i;
	bool	hungry;
	t_philo	*philos;

	hungry = true;
	philos = (t_philo *)arg;
	while (hungry)
	{
		i = 0;
		while (i < philos->params->num_philos)
		{
			if (ft_is_full(&philos[i]) == true)
				hungry = false;
			i++;
		}
	}
	ft_stop_all(philos);
	return (NULL);
}
