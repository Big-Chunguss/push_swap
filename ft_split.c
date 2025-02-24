/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:51:34 by antoine           #+#    #+#             */
/*   Updated: 2025/02/24 11:29:41 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_atoi(const char *str)
{
    int    result;
    int    sign;
    int    i;
    
    result = 0;
    sign = 1;
    i = 0;
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] && str[i] >= 48 && str[i] <= 57)
    {
        result *= 10;
	result += str[i] - 48;
	i++;
    }
    result *= sign;
    return (result);
}

int    ft_isspace(int c)
{
    if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
        return (1);
    return (0);
}


char **ft_split(const char *s, char c)
{
    char **res;
    size_t i;
    int j;
    int s_word;
    
    ft_initiate_vars(&i, &j, &s_word);
    res = ft_calloc((word_count(s, c) + 2), sizeof(char *));
    if (!res)
        return (free(res),NULL);
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
    *j = 0;
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

