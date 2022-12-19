/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:23:35 by voszadcs          #+#    #+#             */
/*   Updated: 2022/12/18 21:14:18 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0' )
	{
		i++;
	}
	return (i);
}

void	ft_bzero(void *s, int n)
{
	char	*a;
	int		i;

	a = (char *)s;
	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == 0 && (char)c == 0)
		return ((char *)&s[i]);
	return (0);
}
// void	*ft_free(char *arr)
// {
// 	int	i;

// 	i = ft_strlen(arr);
// 	while (i > 0)
// 	{
// 		free(arr[i]);
// 		i--;
// 	}
// 	free(arr[0]);
// 	return (NULL);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		size1;
	int		size2;


	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	i = 0;
	str = malloc(size1 + size2 + 1);
	if (!str)
		return (NULL);
	while (*s1 != 0)
	{
		str[i++] = *(char *)s1++;
	}
	while (*s2 != 0)
	{
		str[i++] = *(char *)s2++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*dest_cast;
	char	*src_cast;
	size_t	i;	

	src_cast = (char *)src;
	dest_cast = (char *)dest;
	i = -1;
	if (!dest && !src)
		return (0);
	if (dest_cast < src_cast)
	{
		while (++i < n)
			dest_cast[i] = src_cast[i];
	}
	else
	{
		while (n > 0)
		{
			dest_cast[n - 1] = src_cast[n - 1];
			n--;
		}
	}
	return (dest);
}