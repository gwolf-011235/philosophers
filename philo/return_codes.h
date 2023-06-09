/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_codes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:14:45 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/09 21:17:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETURN_CODES_H
# define RETURN_CODES_H


# define MSG_NUMARGS "Wrong number of arguments."
# define MSG_NOTDIGIT "Only digits as input are allowed."
# define MSG_OVERFLOW "Args need to be <= INT_MAX."
# define MSG_TIME "Function gettimeofday() failed."

typedef enum e_err {
	SUCCESS,
	ERROR,
	ERR_NUMARGS,
	ERR_NOTDIGIT,
	ERR_OVERFLOW,
	ERR_TIME
}	t_err;

t_err	ft_print_usage(char *prog_name, t_err err);
t_err	ft_print_err_msg(t_err err, char *prog_name);

#endif