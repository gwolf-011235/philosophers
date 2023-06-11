/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:32:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/11 19:37:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	static t_params	params;
	t_philo			*philos;
	t_fork			*forks;
	t_err			err;

	err = ft_check_args(argc, argv);
	if (err != SUCCESS)
		return (ft_print_err_msg(err, argv[0]));
	err = ft_set_params(&params, argc, argv);
	if (err != SUCCESS)
		return (ft_print_err_msg(err, argv[0]));
	err = ft_setup_vars(&philos, &forks, &params);
	err = ft_spin_threads(philos, &params);
	err = ft_join_threads(philos, &params);
}


