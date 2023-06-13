/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:16:49 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/13 12:28:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <stdint.h>
# include <pthread.h>
# include <stdbool.h>

typedef enum e_stage {
	INIT,
	POST_MALLOC,
	POST_MUTEX_DATA,
	POST_MUTEX_FORK,
	POST_MUTEX_PHILO
}	t_stage;

typedef struct s_params {
	int32_t			num_philos;
	int32_t			time_to_die;
	int32_t			time_to_eat;
	int32_t			time_to_sleep;
	int32_t			times_to_eat;
	int64_t			start_time;
}	t_params;

typedef struct s_fork {
	bool			in_use;
	pthread_mutex_t	m_in_use;
}	t_fork;

typedef struct s_philo {
	int32_t			id;
	pthread_t		thread_id;
	t_params		*params;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int64_t			last_meal;
	pthread_mutex_t	m_last_meal;
	int32_t			meals_ate;
	pthread_mutex_t	m_meals_ate;
	bool			stop_sim;
	pthread_mutex_t	m_stop_sim;
	pthread_mutex_t	*m_print;
}	t_philo;

typedef struct s_data {
	t_philo			*philos;
	t_fork			*forks;
	t_stage			stage;
	pthread_mutex_t	m_print;
	pthread_t		check_life;
	pthread_t		check_full;
	bool			meals;
}	t_data;

#endif