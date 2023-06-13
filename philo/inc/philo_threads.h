/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:11:25 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/13 09:45:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREADS_H
# define PHILO_THREADS_H

# include "philo_struct.h"
# include "return_codes.h"
# include "utils.h"
# include "routine.h"

t_err	ft_spin_threads(t_data *data, t_philo *philos, t_params *params);
t_err	ft_join_threads(t_data *data, t_philo *philos, t_params *params);
t_err	ft_stop_and_join(t_data *data, t_err err, int32_t num_philos);

#endif