/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_codes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:14:45 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/13 08:27:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETURN_CODES_H
# define RETURN_CODES_H

# include <stdio.h>

# define MSG_SUCCESS "All cleaned up. Goodbye!"
# define MSG_UNDEFINED "Something went wrong."
# define MSG_NUMARGS "Wrong number of arguments."
# define MSG_NOTDIGIT "Only digits as input are allowed."
# define MSG_OVERFLOW "Args have to be <= INT_MAX."
# define MSG_ISZERO "First arg [and/or optional last] has to be > 0."
# define MSG_TIME "Function gettimeofday() failed."
# define MSG_MALLOC "Function malloc() failed."
# define MSG_MUTEX_INIT "Initialisation of mutex failed."
# define MSG_MUTEX_DESTROY "Destruction of mutex failed."
# define MSG_THREAD_CREATE "pthread_create() failed."
# define MSG_PANIC "PANIC! Something went wrong during cleanup!"

typedef enum e_err {
	SUCCESS,
	STOP,
	ERR_UNDEFINED,
	ERR_NUMARGS,
	ERR_NOTDIGIT,
	ERR_OVERFLOW,
	ERR_ISZERO,
	ERR_TIME,
	ERR_MALLOC,
	ERR_MUTEX_INIT,
	ERR_MUTEX_DESTROY,
	ERR_THREAD_CREATE,
	PANIC
}	t_err;

t_err	ft_print_usage(t_err err);
t_err	ft_print_err_msg(t_err err);

#endif