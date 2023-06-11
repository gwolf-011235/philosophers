/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:18:20 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/11 19:10:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdint.h>
# include <sys/time.h>
# include <unistd.h>

# include "return_codes.h"

t_err	ft_isdigit(int c);
int32_t	ft_mini_atoi(const char *str);
int64_t	ft_timestamp_in_ms(void);
void	ft_wrapper_usleep(int64_t time_in_ms);

#endif