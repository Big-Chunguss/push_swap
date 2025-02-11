/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:50:16 by antoine           #+#    #+#             */
/*   Updated: 2025/02/11 17:13:40 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct			node
{
	int			data;
	struct node	*previous;
	struct node	*next;
} t_list;

int				ft_atoi(const char *str);

int				main(int argc, char **argv);

int				ft_isspace(int c);

void			ft_displaybackward(struct node *tail);

void			ft_displayforward(struct node *head);

struct node		*ft_newnode(int a);

void			ft_append(struct node **head, struct node **tail, int a);

static int		word_count(const char *str, char c);

static char		*fill_word(const char *str, int start, int end);

static void		*ft_free(char **strs, int count);

static void		ft_initiate_vars(size_t *i, int *j, int *s_word);

char			**ft_split(const char *s, char c);

void			*ft_calloc(size_t count, size_t size);

size_t			ft_strlen(const char *s);

int				ft_check_repetition(char **tab);

// Rotate & swap
void			rotate(struct node **head);
void			ra(struct node **head);
void			rb(struct node **head);
void			rr(struct node **head_a, struct node **head_b);
void			r_rotate(struct node **head);
void			rra(struct node **head);
void			rrb(struct node **head);
void			rrr(struct node **head_a, struct node **head_b);
void			swap(struct node **head);
void			swap_a(struct node **head);
void			swap_b(struct node **head);
void			swap_both(struct node **head_a, struct node **head_b);

#endif
