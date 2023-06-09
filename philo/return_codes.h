/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_codes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:14:45 by gwolf             #+#    #+#             */
/*   Updated: 2023/06/09 11:41:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETURN_CODES_H
# define RETURN_CODES_H

typedef enum e_err {
	SUCCESS,
	ERROR,
	ERR_NUMARGS,
	ERR_NOTDIGIT,
	ERR_INPUT,
	ERR_OVERFLOW
}	t_err;

#endif