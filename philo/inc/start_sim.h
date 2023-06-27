/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:54:25 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/27 10:22:26 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_SIM_H
# define START_SIM_H

# include "philo_struct.h"
# include "return_codes.h"
# include "utils.h"

t_err	ft_set_startup_time(t_philo *philos, t_params *params);
t_err	ft_spin_threads(t_philo *philos, int32_t num_philos);
t_err	ft_join_threads(t_philo *philos, int32_t num_philos);
t_err	ft_stop_and_join(t_philo *philos, int32_t num_philos);
t_err	ft_start_sim(t_philo *philos, t_params *params, bool meals);

//routine_philo.c
void	*ft_philo_life(void *arg);

//routine_monitoring.c
t_err	ft_monitoring(t_philo *philos, bool meals);
t_err	ft_set_status_all(t_philo *philos, t_status status);


#endif