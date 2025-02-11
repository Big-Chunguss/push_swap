/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:06:33 by antoine           #+#    #+#             */
/*   Updated: 2025/02/11 16:39:35 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct node *ft_newnode(int a)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node)
        return (NULL);
    new_node->data = a;
    new_node->previous = NULL;
    new_node->next = NULL;

    return (new_node);
};

void ft_append(struct node **head, struct node **tail, int a)
{
    struct node *node = ft_newnode(a);
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

void ft_displayforward(struct node *head)
{
    struct node *current = head;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void ft_displaybackward(struct node *tail)
{
    struct node *current = tail;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->previous;
    }
}

char **ft_read_one_input(char *str)
{
        int i;
        char **tab;

        i = -1;
        while(str[++i])
        {
            if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
                return (NULL);
        }
        printf("valid input");
        tab = ft_split(str, ' ');
        if (!tab)
            return NULL;
        return (tab);
}

int main(int argc, char **argv)
{
    struct node *head = NULL;
    struct node *tail = NULL;
    int count;
    
    count = 1;
    if (argc <= 1)
        return (0);
    else if (argc == 2)
    {
        printf("only one argument");
        argv = ft_read_one_input(argv[1]);
        if (!argv)
            return (printf(", but its invalid"), 0);
        count--;
    }
    if (!ft_check_repetition(argv))
        return (0);
    while (argv[count])
    {
        if (!ft_atoi(argv[count]))
            return (0);
        ft_append(&head, &tail, ft_atoi(argv[count++]));
    }
    ft_displayforward(head);
    rotate(&head);
    ft_displayforward(head);
    r_rotate(&head);
    ft_displayforward(head);
    swap(&head);
    ft_displayforward(head);
    //ft_displaybackward(tail);
    return (0);
}
