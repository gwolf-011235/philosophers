/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:45:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/15 08:12:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

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
