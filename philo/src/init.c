/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:22:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/12 23:51:11 by gwolf            ###   ########.fr       */
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
t_err	ft_init_philos(t_philo *philos, t_data *data, t_params *params)
{
	int32_t	i;

	i = 0;
	while (i < params->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].params = params;
		philos[i].m_print = &data->m_print;
		philos[i].left_fork = &data->forks[i];
		if (i == (params->num_philos - 1))
			philos[i].right_fork = &data->forks[0];
		else
			philos[i].right_fork = &data->forks[i + 1];
		i++;
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
t_err	ft_setup_vars(t_data *data, t_params *params)
{
	t_err	err;

	err = ft_malloc_arrays(&data->philos, &data->forks, params->num_philos);
	if (err != SUCCESS)
		return (err);
	data->stage = POST_MALLOC;
	if (pthread_mutex_init(&data->m_print, NULL) != 0)
		return (ERR_MUTEX_INIT);
	data->stage = POST_MUTEX_DATA;
	err = ft_m_init_forks_in_use(data->forks, params->num_philos);
	if (err != SUCCESS)
		return (err);
	data->stage = POST_MUTEX_FORK;
	err = ft_init_philos(data->philos, data, params);
	if (err != SUCCESS)
		return (err);
	err = ft_m_init_philos(data->philos, params->num_philos);
	if (err != SUCCESS)
		return (err);
	data->stage = POST_MUTEX_PHILO;
	return (SUCCESS);
}