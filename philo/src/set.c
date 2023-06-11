/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:45:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/11 10:48:05 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

t_err	ft_set_philo_stop_sim(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_stop_sim);
	philo->stop_sim = true;
	pthread_mutex_unlock(&philo->m_stop_sim);
	return (SUCCESS);
}

t_err	ft_update_philo_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_last_meal);
	philo->last_meal = ft_timestamp_in_ms();
	pthread_mutex_unlock(&philo->m_last_meal);
	return (SUCCESS);
}