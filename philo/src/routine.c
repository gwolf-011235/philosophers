/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:32:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/15 12:33:17 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

t_err	ft_take_forks_lefthanded(t_philo *philo)
{
	t_status	status;

	status = ACTIVE;
	pthread_mutex_lock(&philo->left_fork->m_in_use);
	ft_get_philo_status(philo, &status);
	if (status >= DEAD)
	{
		pthread_mutex_unlock(&philo->left_fork->m_in_use);
		return (STOP);
	}
	philo->left_fork->in_use = true;
	ft_print(philo, FORK);
	pthread_mutex_lock(&philo->right_fork->m_in_use);
	ft_get_philo_status(philo, &status);
	if (status >= DEAD)
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
	t_status	status;

	status = ACTIVE;
	pthread_mutex_lock(&philo->right_fork->m_in_use);
	ft_get_philo_status(philo, &status);
	if (status >= DEAD)
	{
		pthread_mutex_unlock(&philo->right_fork->m_in_use);
		return (STOP);
	}
	philo->right_fork->in_use = true;
	ft_print(philo, FORK);
	pthread_mutex_lock(&philo->left_fork->m_in_use);
	ft_get_philo_status(philo, &status);
	if (status >= DEAD)
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
	err = ft_update_philo_last_meal(philo);
	if (err != SUCCESS)
		return (err);
	ft_print(philo, EAT);
	ft_wrapper_usleep(philo->params->time_to_eat);
	err = ft_update_philo_meals_ate(philo);
	if (err != SUCCESS)
		return (err);
	err = ft_drop_forks(philo);
	if (err != SUCCESS)
		return (err);
	return (SUCCESS);
}

t_err	ft_sleep(t_philo *philo)
{
	t_status	status;

	status = ACTIVE;

	ft_get_philo_status(philo, &status);
	if (status >= DEAD)
		return (STOP);
	ft_print(philo, SLEEP);
	ft_wrapper_usleep(philo->params->time_to_sleep);
	return (SUCCESS);
}

t_err	ft_think(t_philo *philo)
{
	t_status	status;

	status = ACTIVE;

	ft_get_philo_status(philo, &status);
	if (ft_is_dead(philo) || status >= DEAD)
		return (STOP);
	ft_print(philo, THINK);
	return (SUCCESS);
}

void	*ft_philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->params->num_philos == 1)
	{
		pthread_mutex_lock(&philo->left_fork->m_in_use);
		philo->left_fork->in_use = true;
		ft_print(philo, FORK);
		ft_wrapper_usleep(philo->params->time_to_die + 1);
		ft_is_dead(philo);
		philo->left_fork->in_use = false;
		pthread_mutex_unlock(&philo->left_fork->m_in_use);
		return (NULL);
	}
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
