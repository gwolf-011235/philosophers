/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:33:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/27 09:10:01 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_struct.h"
# include "return_codes.h"

t_err	ft_handle_input(t_params *params, int argc, char **argv, bool *meals);
t_err	ft_init_sim(t_data *data, t_params *params);
t_err	ft_start_sim(t_philo *philos, t_params *params, bool *meals);
t_err	ft_cleanup(t_data *data, t_err err, int32_t num_philos);

#endif