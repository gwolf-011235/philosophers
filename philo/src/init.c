/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:22:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/11 19:27:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

/**
 * @brief Malloc philos and forks array and memset to zero.
 *
 * @param philos Philos array.
 * @param forks Forks array.
 * @param num_philos Number of philos.
 * @return t_err SUCCESS, ERR_MALLOC
 */
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

/**
 * @brief Init vars of every t_philo struct in philos array.
 *
 * Sets id, params, left_fork, right_fork.
 * Init mutex with ft_m_init_philos_last_meal() and
 * ft_init_philos_stop_sim().
 * Does not set last_meal and stop_sim since already zero.
 *
 * @param philos Philos array.
 * @param forks Forks array.
 * @param params Pointer to params.
 * @return t_err SUCCESS, ERR_MUTEX_INIT, ERR_MUTEX_DESTROY
 */
t_err	ft_init_philos(t_philo *philos, t_fork *forks, t_params *params)
{
	int32_t	i;
	t_err	err;

	i = 0;
	while (i < params->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].params = params;
		philos[i].left_fork = &forks[i];
		if (i == (params->num_philos - 1))
			philos[i].right_fork = &forks[0];
		else
			philos[i].right_fork = &forks[i + 1];
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

/**
 * @brief Driver ft to init simulation.
 *
 * @param philos Philos array.
 * @param forks Forks array.
 * @param params Pointer to params.
 * @return t_err SUCCESS, ERR_MALLOC, ERR_MUTEX_INIT
 */
t_err	ft_setup_vars(t_philo **philos, t_fork **forks, t_params *params)
{
	t_err	err;

	if (pthread_mutex_init(&params->m_print, NULL) != 0)
		return (ERR_MUTEX_INIT);
	err = ft_malloc_arrays(philos, forks, params->num_philos);
	if (err != SUCCESS)
		return (err);
	err = ft_m_init_forks_in_use(*forks, params->num_philos);
	if (err != SUCCESS)
	//TODO: cleanup malloc
		return (err);
	err = ft_init_philos(*philos, *forks, params);
	if (err != SUCCESS)
	//TODO: cleanup malloc and mutex forks
		return (err);
	return (SUCCESS);
}
