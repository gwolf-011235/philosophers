/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:22:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/09 23:10:59 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_err	ft_malloc_stuff(t_philo **philos, t_fork **forks, int32_t num_philos)
{
	*philos = malloc(sizeof(t_philo) * num_philos);
	if (!*philos)
		return (ERR_MALLOC);
	*forks = malloc(sizeof(t_fork) * num_philos);
	if (!*forks)
	{
		free(philos);
		return (ERR_MALLOC);
	}
	return (SUCCESS);
}

t_err	ft_init_forks(t_fork **forks, int32_t num_philos)
{
	int32_t	i;
	bool	init_fail;

	i = 0;
	init_fail = false;
	while (i < num_philos)
	{
		forks[i]->in_use = false;
		if (pthread_mutex_init(&forks[i]->m_fork, NULL) != 0)
		{
			init_fail = true;
			break ;
		}
		i++;
	}
	if (init_fail)
	{
		while (--i > -1)
			pthread_mutex_destroy(&forks[i]->m_fork);
		return (ERR_MUTEX_INIT);
	}
	return (SUCCESS);
}

t_err	ft_init_philos(t_philo **philos, t_fork **forks, t_params *params)
{
	int32_t	i;

	i = 0;
	while (i < params->num_philos)
	{
		philos[i]->id = i + 1;
		philos[i]->params = params;
		philos[i]->left_fork = forks[i];
		if (i == params->num_philos - 1)
			philos[i]->right_fork = forks[0];
		else
			philos[i]->right_fork = forks[i + 1];
		philos[i]->last_meal = 0;
		philos[i]->meals_ate = 0;
		i++;
	}
}

t_err	ft_setup_vars(t_philo **philos, t_fork **forks, t_params *params)
{
	t_err	err;

	err = ft_malloc_stuff(philos, forks, params->num_philos);
	if (err != SUCCESS)
		return (err);
	err = ft_init_forks(forks, params->num_philos);
	if (err != SUCCESS)
		return (err);
	err = ft_init_philos(philos, forks, params);
	if (err != SUCCESS)
		return (err);
}
