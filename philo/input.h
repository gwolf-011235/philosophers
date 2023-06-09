/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:20:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/09 21:12:17 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stdio.h>

# include "philo_struct.h"
# include "return_codes.h"
# include "utils.h"
# include "time.h"

t_err	ft_check_args(int argc, char **argv);
t_err	ft_set_params(t_params *params, int argc, char **argv);

#endif