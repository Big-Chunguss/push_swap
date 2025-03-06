/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:08:29 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/05 15:43:02 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_list **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (!ft_check_repetition(argv))
			error_free(a, argv, flag_argc_2);
		ft_append(a, (int)nbr);
		++i;
	}
	if (flag_argc_2)
		free_matrix(argv);
}