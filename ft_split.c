/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:51:34 by antoine           #+#    #+#             */
/*   Updated: 2025/02/24 11:56:09 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **ft_split(const char *s, char c)
{
    char **res;
    size_t i;
    int j;
    int s_word;
    
    ft_initiate_vars(&i, &j, &s_word);
    res = ft_calloc((word_count(s, c) + 2), sizeof(char *));
    //printf("%d", word_count(s, c));
    if (!res)
        return (free(res),NULL);
    res[0] = fill_word("", 0, 0);
    while (i <= ft_strlen(s))
    {
        if (s[i] != c && s_word < 0)
            s_word = i;
        else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
        {
            res[j] = fill_word(s, s_word, i);
            if (!(res[j]))
                return (ft_free(res, j));
            s_word = -1;
            j++;
        }
        i++;
    }
    return (res);
}

void ft_initiate_vars(size_t *i, int *j, int *s_word)
{
    *i = 0;
    *j = 1;
    *s_word = -1;
}

void *ft_free(char **strs, int count)
{
    int i;
    
    i = 0;
    while (i< count)
    {
        free(strs[i]);
        i++;
    }
    free(strs);
    return (NULL);
}

char *fill_word(const char *str, int start, int end)
{
    char *word;
    int i;
    
    i = 0;
    word = malloc((end - start + 1) * sizeof(char));
    if (!word)
        return (NULL);

    while (start < end)
    {
        word[i] = str[start];
        i++;
        start++;
    }
    word[i] = 0;
    //printf("%s\n", word);
    return (word);
}

int word_count(const char *str, char c)
{
    int count;
    int x;
    
    count = 0;
    x = 0;
    while (*str)
    {
        if (*str != c && x == 0)
        {
            x = 1;
            count++;
        }
        else if (*str == c)
            x = 0;
        str++;
    }
    return (count);
}

