/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:38:47 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/15 08:09:37 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

t_err	ft_get_philo_status(t_philo *philo, t_status *status)
{
	pthread_mutex_lock(&philo->m_status);
	*status = philo->status;
	pthread_mutex_unlock(&philo->m_status);
	return (SUCCESS);
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
