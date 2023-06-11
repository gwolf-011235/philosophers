/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:54:07 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/11 11:32:09 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int32_t	ft_mini_atoi(const char *str)
{
	uint32_t	i;
	int64_t		num;

	i = 0;
	num = 0;
	while (str[i])
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (num > INT32_MAX)
		return (-1);
	return ((int)num);
}

t_err	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (SUCCESS);
	else
		return (ERR_NOTDIGIT);
}

int64_t	ft_timestamp_in_ms(void)
{
	struct timeval	tv;
	int64_t			ms;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}

void	ft_wrapper_usleep(int64_t time_in_ms)
{
	int64_t	start_time;

	start_time = ft_timestamp_in_ms();
	while ((ft_timestamp_in_ms() - start_time - time_in_ms) < 0)
		usleep(100);
}