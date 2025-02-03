/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:49:13 by agaroux           #+#    #+#             */
/*   Updated: 2025/02/03 18:15:59 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

struct					t_list
{
	int					data;
	struct t_list		*previous;
	struct t_list		*next;
};

typedef struct t_list	t_list;

t_list					*ft_lstnew(void *content);

void					ft_lstadd_front(t_list **lst, t_list *new);

int						ft_lstsize(t_list *lst);

t_list					*ft_lstlast(t_list *lst);

void					ft_lstadd_back(t_list **lst, t_list *new);

void					ft_lstdelone(t_list *lst, void (*del)(void *));

void					ft_lstclear(t_list **lst, void (*del)(void *));

void					ft_lstiter(t_list *lst, void (*f)(void *));

#endif