/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:55:51 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/06/29 13:55:53 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isprint(int c)
{
	if (c <= 126 && c >= 32)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	int	ft_found(const char *str, const char *find)
{
	int	i;

	i = 0;
	while (str[i] == find[i] && find[i] != 0)
		i++;
	if (find[i] == 0)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str2;

	str2 = (char *)str;
	j = 0;
	if (str == 0 || find == 0)
		return (0);
	while (find[j])
		j++;
	if (j == 0)
		return (str2);
	i = 0;
	while (str[i] != 0 && i + j < n + 1)
	{
		if (ft_found(&str[i], find))
			return (&str2[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	size;

	if (str == 0)
		return (0);
	size = ft_strlen(str);
	sub = malloc(len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (str[start + i] && i < len && start + i <= size)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
