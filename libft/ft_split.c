/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:45:17 by jde-orma          #+#    #+#             */
/*   Updated: 2023/01/19 18:45:17 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char **ft_count_substrings(char const *s, char c)
{
    size_t  i;
    size_t  count;
    char    **ptr;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] == c)
            count++;
        i++;
    }
    ptr = (char**)malloc(sizeof(*s) * (count + 2));
    if (!ptr)
        return (NULL);
    return (ptr);   
}

char **ft_alloc_substrings (char **ptr, char const *s, char c, int count)
{
    size_t  i;
    size_t  start;
    size_t  substring_id;

    i = 0;
    start = 0;
    substring_id = 0;
    while (s[i])
    {
        if (s[i] == c)
        {
            (**ptr + substring_id) = ft_substr(s, start, i - start);
            substring_id++;
            start = i + 1;
        }
        i++;
    }
    (**ptr + substring_id) = NULL;
    return (ptr);
}

char    **ft_split(char const *s, char c)
{
    char**  ptr;

    if (!s)
        return(NULL);
    ptr = ft_count_substrings(s, c);
    if (!ptr)
        return (NULL);
    ptr = ft_alloc_substrings(ptr, s, c, ft_strlen(ptr));
    return(ptr);
}
