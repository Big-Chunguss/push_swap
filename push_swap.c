/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:06:33 by antoine           #+#    #+#             */
/*   Updated: 2025/02/24 11:34:30 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_newnode(int a)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->data = a;
    new_node->previous = NULL;
    new_node->next = NULL;

    return (new_node);
};

void ft_append(t_list **head, t_list **tail, int a)
{
    t_list *node = ft_newnode(a);
    if (!*head) //if the list is empty
        {
            *head = node;
            *tail = node;
        } else {
            (*tail)->next = node;
            node ->previous = *tail;
            *tail = node;
        }
}

void ft_displayforward(t_list *head)
{
    t_list *current = head;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void ft_displaybackward(t_list *tail)
{
    t_list *current = tail;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->previous;
    }
}

t_list *ft_read_one_input(char *str, t_list *head, t_list *tail)
{
        int i;
        char **tab;

        i = 0;
        while (str[i])
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
        {
            write(2, "Error: Invalid input\n", 21);
            return 0;
        }
        i++;
    }
        tab = ft_split(str, ' ');
        if (!tab)
            return NULL;
        i = 0;
        while (tab[i])
        {
            int num = ft_atoi(tab[i]);
        ft_append(&head, &tail, num);
        free(tab[i]);
        i++;
        }
        free(tab);
        return (head);
}

int main(int argc, char **argv)
{
    t_list *head = NULL;
    t_list *tail = NULL;
    int count;

    if (argc <= 1 || (argc == 2 && !argv[1][0]))
        return (0);
    else if (argc == 2)
    {
        printf("only one argument");
        ft_read_one_input(argv[1], head, tail);
        return (0);
    }
    count = 1;
    while (count < argc)
    {
        if (!ft_atoi(argv[count]))
            return (0);
        ft_append(&head, &tail, ft_atoi(argv[count++]));
    }
    ft_displayforward(head);
    ft_displaybackward(tail);
    return (0);
}
