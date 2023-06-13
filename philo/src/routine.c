/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:32:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/13 13:04:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

t_err	ft_take_forks_lefthanded(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->m_in_use);
	if (ft_get_philo_stop_sim(philo))
	{
		pthread_mutex_unlock(&philo->left_fork->m_in_use);
		return (STOP);
	}
	philo->left_fork->in_use = true;
	ft_print(philo, FORK);
	pthread_mutex_lock(&philo->right_fork->m_in_use);
	if (ft_get_philo_stop_sim(philo))
	{
		philo->left_fork->in_use = false;
		pthread_mutex_unlock(&philo->left_fork->m_in_use);
		pthread_mutex_unlock(&philo->right_fork->m_in_use);
		return (STOP);
	}
	philo->right_fork->in_use = true;
	ft_print(philo, FORK);
	return (SUCCESS);
}

t_err	ft_take_forks_righthanded(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->m_in_use);
	if (ft_get_philo_stop_sim(philo))
	{
		pthread_mutex_unlock(&philo->right_fork->m_in_use);
		return (STOP);
	}
	philo->right_fork->in_use = true;
	ft_print(philo, FORK);
	pthread_mutex_lock(&philo->left_fork->m_in_use);
	if (ft_get_philo_stop_sim(philo))
	{
		philo->right_fork->in_use = false;
		pthread_mutex_unlock(&philo->right_fork->m_in_use);
		pthread_mutex_unlock(&philo->left_fork->m_in_use);
		return (STOP);
	}
	philo->left_fork->in_use = true;
	ft_print(philo, FORK);
	return (SUCCESS);
}

t_err	ft_drop_forks(t_philo *philo)
{
	philo->left_fork->in_use = false;
	pthread_mutex_unlock(&philo->left_fork->m_in_use);
	philo->right_fork->in_use = false;
	pthread_mutex_unlock(&philo->right_fork->m_in_use);
	return (SUCCESS);
}

t_err	ft_eat(t_philo *philo)
{
	t_err	err;

	if (ft_is_dead(philo))
		return (STOP);
	if (philo->id % 2 == 0)
		err = ft_take_forks_lefthanded(philo);
	else
		err = ft_take_forks_righthanded(philo);
	if (err != SUCCESS)
		return (err);
	ft_update_philo_last_meal(philo);
	ft_print(philo, EAT);
	ft_wrapper_usleep(philo->params->time_to_eat);
	ft_update_philo_meals_ate(philo);
	ft_drop_forks(philo);
	return (SUCCESS);
}

t_err	ft_sleep(t_philo *philo)
{
	if (ft_get_philo_stop_sim(philo))
		return (STOP);
	ft_print(philo, SLEEP);
	ft_wrapper_usleep(philo->params->time_to_sleep);
	return (SUCCESS);
}

t_err	ft_think(t_philo *philo)
{
	if (ft_is_dead(philo) || ft_get_philo_stop_sim(philo))
		return (STOP);
	ft_print(philo, THINK);
	return (SUCCESS);
}

void	*ft_philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ft_eat(philo) != SUCCESS)
			break ;
		if (ft_sleep(philo) != SUCCESS)
			break ;
		if (ft_think(philo) != SUCCESS)
			break ;
	}
	return (NULL);
}
