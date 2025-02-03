#include <stdio.h>
#include <stdlib.h>

// Assuming your t_list structure is defined like this:
typedef struct s_list
{
    int data;
    struct s_list *previous;
    struct s_list *next;
} t_list;

// Your ft_lstnew and ft_lstadd_front functions here...

// Function to print the list
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("Address previous: %x", lst->previous);
        printf("\nAddress current: %x", lst);
        printf("\nAddress next: %x", lst->next);
        printf(" %d\n\n", lst->data);
        
        lst = lst->next;
    }
    printf("\n");
}

t_list    *ft_lstnew(int data)
{
    t_list *elem;
    elem = malloc(sizeof(t_list));
    if (!elem)
        return(NULL);
    elem->data = data;
    elem->previous = NULL;
    elem->next = NULL;

    return(elem);
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (lst && new)
    {
        new->next = *lst;
        if (*lst)
            (*lst)->previous = new;
        *lst = new;
    }
}

int main()
{
    t_list *lst = NULL;
    t_list *new_node;

    // Create and add nodes to the front of the list
    new_node = ft_lstnew(3);
    ft_lstadd_front(&lst, new_node);

    new_node = ft_lstnew(2);
    ft_lstadd_front(&lst, new_node);

    new_node = ft_lstnew(1);
    ft_lstadd_front(&lst, new_node);

    // Print the list
    printf("List contents: ");
    print_list(lst);

    // Free the list (you should implement a function for this)
    while (lst)
    {
        t_list *temp = lst;
        lst = lst->next;
        free(temp);
    }

    return 0;
}