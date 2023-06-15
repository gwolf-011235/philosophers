/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:32:44 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/15 08:56:59 by gwolf            ###   ########.fr       */
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
	if (ft_timestamp_in_ms() - philo->last_meal >= philo->params->time_to_die)
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

t_err	ft_still_alive(t_philo *philos, int32_t num_philos, bool *alive)
{
	t_status	status;
	int32_t		i;

	status = ACTIVE;
	i = 0;
	while (*alive && i < num_philos)
	{
		ft_get_philo_status(&philos[i], &status);
		if (status == FULL_STOP)
			return (STOP);
		else if (status == DEAD || ft_is_dead(&philos[i]) == true)
			*alive = false;
		i++;
	}
	return (SUCCESS);

}

void	*ft_check_life(void *arg)
{
	t_err	err;
	t_philo	*philos;
	bool	alive;

	philos = (t_philo *)arg;
	alive = true;
	while (alive)
	{
		err = ft_still_alive(philos, philos->params->num_philos, &alive);
		if (err != SUCCESS)
			break ;
	}
	if (err == SUCCESS)
		ft_set_status_all(philos, DEAD);
	return (NULL);
}

t_err	ft_still_hungry(t_philo *philos, int32_t num_philos, bool *hungry)
{
	t_status	status;
	int32_t		i;
	int32_t		philos_fed;

	status = ACTIVE;
	i = 0;
	philos_fed = 0;
	while (i < num_philos)
	{
		ft_get_philo_status(&philos[i], &status);
		if (status == DEAD)
			return (STOP);
		else if (status == FULL)
			philos_fed++;
		else
		{
			if (ft_is_full(&philos[i]) == true)
				philos_fed++;
		}
		i++;
	}
	if (philos_fed == num_philos)
		*hungry = false;
	return (SUCCESS);
}

void	*ft_check_full(void *arg)
{
	t_err	err;
	t_philo	*philos;
	bool	hungry;

	philos = (t_philo *)arg;
	hungry = true;
	while (hungry)
	{
		err = ft_still_hungry(philos, philos->params->num_philos, &hungry);
		if (err != SUCCESS)
			break ;
	}
	if (err == SUCCESS)
		ft_set_status_all(philos, FULL_STOP);
	return (NULL);
}
