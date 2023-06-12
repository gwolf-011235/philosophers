/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:50:27 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/13 00:30:45 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "return_codes.h"

t_err	ft_print_usage(t_err err)
{
	printf("\n🧠 Usage: ./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (err);
}

t_err	ft_print_err_msg(t_err err)
{
	static const char	*msg_look_up[128] = {
	[SUCCESS] = MSG_SUCCESS,
	[ERR_UNDEFINED] = MSG_UNDEFINED,
	[ERR_NUMARGS] = MSG_NUMARGS,
	[ERR_NOTDIGIT] = MSG_NOTDIGIT,
	[ERR_OVERFLOW] = MSG_OVERFLOW,
	[ERR_ISZERO] = MSG_ISZERO,
	[ERR_TIME] = MSG_TIME,
	[ERR_MALLOC] = MSG_MALLOC,
	[ERR_MUTEX_INIT] = MSG_MUTEX_INIT,
	[ERR_MUTEX_DESTROY] = MSG_MUTEX_DESTROY,
	[PANIC] = MSG_PANIC
	};

	if (err == SUCCESS)
		printf("%s\n", msg_look_up[err]);
	else
		printf("😵 Error: %s\n", msg_look_up[err]);
	if (err == ERR_NUMARGS || err == ERR_NOTDIGIT
		|| err == ERR_OVERFLOW)
		ft_print_usage(err);
	return (err);
}
