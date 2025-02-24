/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:48:45 by agaroux           #+#    #+#             */
/*   Updated: 2025/02/22 17:48:06 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->previous = NULL;
	elem->next = NULL;
	return (elem);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		if (*lst)
			(*lst)->previous = new;
		*lst = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->previous = last;
}

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	del(lst->data);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(int))
{
    t_list *current;
    t_list *next;

    if (!lst || !del)
        return;
    current = *lst;
    while (current)
		{
            next = current->next;
            if (next)
                next->previous = NULL;
            ft_lstdelone(current, del);
            current = next;
        }
        *lst = NULL;
}

void ft_lstiter(t_list *lst, void (*f)(int))
{
    t_list *tmp;

    tmp = lst;
    while (tmp)
        {
            f(tmp->data);
            tmp = tmp->next;
        }
}