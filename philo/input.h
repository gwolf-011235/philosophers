/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:20:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/09 11:42:45 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stdio.h>

# include "philo_struct.h"
# include "return_codes.h"
# include "utils.h"

t_err	ft_check_args(int argc, char **argv);
t_err	ft_print_usage(char *prog_name, t_err err);
t_err	ft_set_params(t_params *params, int argc, char **argv);

#endif