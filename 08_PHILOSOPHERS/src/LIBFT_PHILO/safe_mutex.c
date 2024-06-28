/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimcak <psimcak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:54:58 by psimcak           #+#    #+#             */
/*   Updated: 2024/06/28 17:39:36 by psimcak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

/**
 * Handle error messages for mutex operations from man. It makes the code more
 * robust and easier to maintain.
 */
static int	handle_error(int err, t_func_type type)
{
	if (err == EINVAL && (type == LOCK || type == UNLOCK || type == DESTROY))
		return (printf("%sThe value specified by mutex is invalid.%s\n",
				R, RST));
	if (err == EINVAL && type == INIT)
		return (printf("%sThe value specified by attr is invalid.%s\n",
				R, RST));
	if (err == EDEADLK && type == LOCK)
		return (printf("%sA deadlock would occur if the thread blocked waiting \
				for mutex.%s\n", R, RST));
	if (err == EPERM && type == UNLOCK)
		return (printf("%sThe current thread does not hold a lock on mutex%s\n",
				R, RST));
	if (err == ENOMEM && type == INIT)
		return (printf("%sThe process cannot allocate enough memory to create \
				another mutex.%s\n", R, RST));
	if (err == EBUSY && type == DESTROY)
		return (printf("%sMutex is locked.%s\n", R, RST));
	return (SUCCESS);
}

/**
 * Safe mutex function to handle mutex operations such as:
 * LOCK, UNLOCK, INIT, DESTROY
 */
int	safe_mutex(t_mutex *mutex, t_func_type type)
{
	int	err;

	if (type == LOCK)
		err = pthread_mutex_lock(mutex);
	if (type == UNLOCK)
		err = pthread_mutex_unlock(mutex);
	if (type == INIT)
		err = pthread_mutex_init(mutex, NULL);
	if (type == DESTROY)
		err = pthread_mutex_destroy(mutex);
	if (handle_error(err, type))
		return (FAILURE);
	return (SUCCESS);
}
