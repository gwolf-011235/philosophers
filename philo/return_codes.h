/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_codes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:14:45 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/10 22:17:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETURN_CODES_H
# define RETURN_CODES_H


# define MSG_NUMARGS "Wrong number of arguments."
# define MSG_NOTDIGIT "Only digits as input are allowed."
# define MSG_OVERFLOW "Args have to be <= INT_MAX."
# define MSG_ISZERO "First arg [and/or optional last] has to be > 0."
# define MSG_TIME "Function gettimeofday() failed."
# define MSG_MALLOC "Function malloc() failed."
# define MSG_MUTEX_INIT "CRITICAL: Initialisation of mutex failed."
# define MSG_MUTEX_DESTROY "CRITICAL: Destruction of mutex failed."

typedef enum e_err {
	SUCCESS,
	ERROR,
	ERR_NUMARGS,
	ERR_NOTDIGIT,
	ERR_OVERFLOW,
	ERR_ISZERO,
	ERR_TIME,
	ERR_MALLOC,
	ERR_MUTEX_INIT,
	ERR_MUTEX_DESTROY
}	t_err;

t_err	ft_print_usage(char *prog_name, t_err err);
t_err	ft_print_err_msg(t_err err, char *prog_name);

#endif