/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peta <peta@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:01:25 by psimcak           #+#    #+#             */
/*   Updated: 2023/10/27 12:18:19 by peta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_create_stack(&a, argv);
	if (!sorted_stack(a))
	 	ft_push_swap(&a, &b);
	// free_stack();
	return (0);
}
