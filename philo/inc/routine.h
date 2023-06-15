/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:33:01 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/15 16:35:40 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include <stdbool.h>
# include <stdio.h>

# include "philo_struct.h"
# include "return_codes.h"
# include "utils.h"

typedef enum e_msg {
	FORK = 0,
	EAT = 1,
	SLEEP = 2,
	THINK = 3,
	DIED = 4
}	t_msg;

//print.c
void	ft_print(t_philo *philo, t_msg index);

//get.c
t_err	ft_get_philo_status(t_philo *philo, t_status *status);
int64_t	ft_get_philo_last_meal(t_philo *philo);

//set.c
t_err	ft_set_philo_status(t_philo *philo, t_status status);
t_err	ft_update_philo_last_meal(t_philo *philo);
t_err	ft_update_philo_meals_ate(t_philo *philo);

//monitoring.c
t_err	ft_set_status_all(t_philo *philos, t_status status);
bool	ft_is_dead(t_philo *philo);
bool	ft_is_full(t_philo *philo);
t_err	ft_dead_or_full(t_philo *philos, int32_t num_philos,
			bool *alive, bool *hungry, bool meals);
t_err	ft_monitoring(t_philo *philos, int32_t num_philos, bool meals);

//routine.c
void	*ft_philo_life(void *arg);

#endif