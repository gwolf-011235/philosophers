/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:38:47 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/13 10:32:42 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

bool	ft_get_philo_stop_sim(t_philo *philo)
{
	bool	ret;

	pthread_mutex_lock(&philo->m_stop_sim);
	ret = philo->stop_sim;
	pthread_mutex_unlock(&philo->m_stop_sim);
	return (ret);
}

int64_t	ft_get_philo_last_meal(t_philo *philo)
{
	int64_t	ret;

	pthread_mutex_lock(&philo->m_last_meal);
	ret = philo->last_meal;
	pthread_mutex_unlock(&philo->m_last_meal);
	return (ret);
}

int32_t	ft_get_philo_meals_ate(t_philo *philo)
{
	int32_t	ret;

	pthread_mutex_lock(&philo->m_meals_ate);
	ret = philo->meals_ate;
	pthread_mutex_unlock(&philo->m_meals_ate);
	return (ret);
}
