/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:50:16 by antoine           #+#    #+#             */
/*   Updated: 2025/02/24 15:44:16 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct node
{
	int			data;
	struct node	*previous;
	struct node	*next;
} 	t_list;

int				ft_atoi(const char *str);

int				main(int argc, char **argv);

int				ft_isspace(int c);

void			ft_displaybackward(t_list *tail);

void			ft_displayforward(t_list *head);

t_list		*ft_newnode(int a);

void			ft_append(t_list **head, t_list **tail, int a);

 int		word_count(const char *str, char c);

 char		*fill_word(const char *str, int start, int end);

 void		*ft_free(char **strs, int count);

 void		ft_initiate_vars(size_t *i, int *j, int *s_word);

char			**ft_split(const char *s, char c);

void			*ft_calloc(size_t count, size_t size);

size_t			ft_strlen(const char *s);

int				ft_check_repetition(char **tab);

t_list			*ft_lstnew(int data);

void	ft_lstadd_front(t_list **lst, t_list *new);

int 	ft_isdigit(char **tab);

void	stack_init(t_list **a, t_list **b, char **argv, bool flag_argc_2);

//free
void 	free_matrix(char **argv);
void 	free_stack(t_list **stack);
void 	error_free(t_list **stack, char **argv, bool flag_argc_2);

//sort
t_list	*ft_max(t_list *head);
void 	ez_sort(t_list **head);

// Rotate & swap
void			rotate(t_list **head);
void			ra(t_list **head);
void			rb(t_list **head);
void			rr(t_list **head_a, t_list **head_b);
void			r_rotate(t_list **head);
void			rra(t_list **head);
void			rrb(t_list **head);
void			rrr(t_list **head_a, t_list **head_b);
void			swap(t_list **head);
void			swap_a(t_list **head);
void			swap_b(t_list **head);
void			swap_both(t_list **head_a, t_list **head_b);

#endif
