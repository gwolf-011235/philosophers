/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:23:41 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/09 23:16:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "stdlib.h"

# include "philo_struct.h"
# include "return_codes.h"

t_err	ft_malloc_stuff(t_philo **philos, t_fork **forks, int32_t num_philos);

#endif