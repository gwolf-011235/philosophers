/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:29:38 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/09 21:23:04 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

int64_t	ft_timestamp_in_ms(void)
{
	struct timeval	tv;
	int64_t			ms;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}
