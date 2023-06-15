/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:50:27 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/15 14:10:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "return_codes.h"

t_err	ft_strlen(const char *str, uint32_t *len)
{
	uint32_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	*len = i;
	return (SUCCESS);
}

t_err	ft_print_usage(t_err err)
{
	if (write (2, "\n🧠 Usage: ./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 127) != 127)
		return (PANIC);
	return (err);
}

t_err	ft_write_err(t_err err)
{
	static const char	*msg_look_up[128] = {
	[SUCCESS] = MSG_SUCCESS,
	[ERR_UNDEFINED] = MSG_UNDEFINED,
	[ERR_NUMARGS] = MSG_NUMARGS,
	[ERR_NOTDIGIT] = MSG_NOTDIGIT,
	[ERR_EMPTY_STR] = MSG_EMPTY_STR,
	[ERR_OVERFLOW] = MSG_OVERFLOW,
	[ERR_ISZERO] = MSG_ISZERO,
	[ERR_TIME] = MSG_TIME,
	[ERR_MALLOC] = MSG_MALLOC,
	[ERR_MUTEX_INIT] = MSG_MUTEX_INIT,
	[ERR_MUTEX_DESTROY] = MSG_MUTEX_DESTROY,
	[ERR_THREAD_CREATE] = MSG_THREAD_CREATE,
	[PANIC] = MSG_PANIC
	};
	uint32_t			len;

	len = 0;
	ft_strlen(msg_look_up[err], &len);
	if (write(2, msg_look_up[err], len) != len)
		return (PANIC);
	return (SUCCESS);
}

t_err	ft_print_err_msg(t_err err)
{
	if (err == SUCCESS)
		printf("%s\n", MSG_SUCCESS);
	else
	{
		if (write(2, "😵 Error: ", 12) != 12)
			return (PANIC);
		if (ft_write_err(err) != SUCCESS)
			return (PANIC);
	}
	if (err == ERR_NUMARGS || err == ERR_NOTDIGIT
		|| err == ERR_OVERFLOW)
		ft_print_usage(err);
	return (err);
}
