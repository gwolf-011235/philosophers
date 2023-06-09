/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:54:07 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/09 11:51:20 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int32_t	ft_mini_atoi(const char *str)
{
	uint32_t	i;
	int64_t	num;

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
