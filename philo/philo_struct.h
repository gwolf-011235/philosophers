/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:16:49 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/09 20:46:17 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <stdint.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_params {
	int32_t	num_philos;
	int32_t	time_to_die;
	int32_t	time_to_eat;
	int32_t	time_to_sleep;
	int32_t	times_to_eat;
	int64_t	start_time;
}	t_params;

typedef struct s_fork {
	bool			in_use;
	pthread_mutex_t	m_fork;
}	t_fork;

typedef struct s_philo {
	int32_t			id;
	pthread_t		thread;
	t_params		*params;
	t_fork			*left_fork;
	t_fork			*right_fork;
	uint64_t		last_meal;
	int32_t			meals_ate;
	bool			*philo_dead;
	pthread_mutex_t	*m_philo_dead;
}	t_philo;

#endif