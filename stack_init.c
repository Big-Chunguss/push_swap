/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:08:29 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/03 15:23:52 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_list **head, char **argv, bool flag_argc_2)
{
    int count;
    
    if(!ft_check_repetition(argv) || !ft_isdigit(argv))
        return (error_free(head, argv, flag_argc_2));
    count = 0;
    while (argv[count])
        ft_append(head, ft_atoi(argv[count++]));
    if (flag_argc_2)
        free_matrix(argv);
}