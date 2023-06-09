/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:50:27 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/09 21:21:56 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "return_codes.h"
#include <stdio.h>

t_err	ft_print_usage(char *prog_name, t_err err)
{
	printf("\n🧠 Usage: %s number_of_philosophers time_to_die time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n", prog_name);
	return (err);
}

t_err	ft_print_err_msg(t_err err, char *prog_name)
{
	static const char	*msg_look_up[128] = {
	[ERR_NUMARGS] = MSG_NUMARGS,
	[ERR_NOTDIGIT] = MSG_NOTDIGIT,
	[ERR_OVERFLOW] = MSG_OVERFLOW,
	[ERR_TIME] = MSG_TIME
	};

	printf("😵 Error: %s\n", msg_look_up[err]);
	if (err == ERR_NUMARGS || err == ERR_NOTDIGIT
		|| err == ERR_OVERFLOW)
		ft_print_usage(prog_name, err);
	return (err);

}