/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:51:47 by agaroux           #+#    #+#             */
/*   Updated: 2025/02/24 15:44:02 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
		tmp[i++] = 0;
	return (tmp);
}

size_t	ft_strlen(const char *s)
{
	size_t i;
    
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_isdigit(char **tab)
{
    int i;
    int j;

    i = 1;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if ((tab[i][j] < '0' || tab[i][j] > '9') && tab[i][j] != 32 && tab[i][j] != 45) 
                return (0);
            j++;  
        }
        i++;
    }
    return (1);
    
}
int ft_check_repetition(char **tab)
{
    int i;
    int j;
    int k;
    
    i = 0;
    while (tab[i])
    {
        j = i + 1;
        while (tab[j])
            {
            k = 0;
            while(tab[i][k] && tab[j][k] && tab[i][k] == tab[j][k])
                k++;
            if (!tab[i][k] && !tab[j][k])
                return (0);
                j++;
            }          
        i++;
        }
    return (1);
}

t_list  *ft_max(t_list *head)
{
    t_list  *tmp;
    int     max;
    
    if (!head)
        return (NULL);
    max = INT_MIN;
    while (head)
    {
        
        if (max < head->data)
        {
            max = head->data;
            tmp = head;
        }
        head = head->next;
    }
    return (tmp);
}

bool ft_sorted(t_list *head)
{
    int i;
    
    if (!head)
        return(false);
    i = INT_MIN;
    while (head)
    {
        if (head->data < i)
            return (false);
        head = head->next;
    }
    return (true);
}