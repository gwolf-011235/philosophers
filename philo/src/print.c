/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:52:53 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/12 23:51:34 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

/**
 * @brief Prints log of state change of a philosopher. Mutex protected.
 *
 * @param philo Philo who prints.
 * @param index	Type of msg: FORK, EAT, SLEEP, THINK, DIED
 */
void	ft_print(t_philo *philo, t_msg index)
{
	static const char	*msg[5] = {
	[FORK] = "has taken a fork",
	[EAT] = "is eating",
	[SLEEP] = "is sleeping",
	[THINK] = "is thinking",
	[DIED] = "died"
	};
	int64_t				curr_timestamp;

	pthread_mutex_lock(philo->m_print);
	curr_timestamp = ft_timestamp_in_ms() - philo->params->start_time;
	printf("%ld %d %s\n", curr_timestamp, philo->id, msg[index]);
	pthread_mutex_unlock(philo->m_print);
}
