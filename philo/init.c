/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:22:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/11 08:35:57 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <string.h>
#include "teardown.h"

t_err	ft_malloc_arrays(t_philo **philos, t_fork **forks, int32_t num_philos)
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
	memset(*philos, 0, sizeof(t_philo) * num_philos);
	memset(*forks, 0, sizeof(t_fork) * num_philos);
	return (SUCCESS);
}

t_err	ft_init_philos(t_philo **philos, t_fork **forks, t_params *params)
{
	int32_t	i;
	t_err	err;

	i = 0;
	while (i < params->num_philos)
	{
		philos[i]->id = i + 1;
		philos[i]->params = params;
		philos[i]->left_fork = forks[i];
		if (i == (params->num_philos - 1))
			philos[i]->right_fork = forks[0];
		else
			philos[i]->right_fork = forks[i + 1];
		i++;
	}
	err = ft_m_init_philos_last_meal(philos, params->num_philos);
	if (err != SUCCESS)
		return (err);
	err = ft_m_init_philos_stop_sim(philos, params->num_philos);
	if (err != SUCCESS)
	{
		ft_m_destroy_philo_last_meal(philos, params->num_philos);
		return (err);
	}
	return (SUCCESS);
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
	return (SUCCESS);
}
