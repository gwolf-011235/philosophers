/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:33:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/08 18:35:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/time.h>

# define ERROR 1

//input.c
int		ft_check_args(int argc, char **argv);
int		ft_print_usage(char *prog_name);

//time.c
int64_t	ft_timestamp_in_ms(void);

#endif