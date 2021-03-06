/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:58:07 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/04 11:58:08 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_hexupperhub(unsigned long long n, char *flags)
{
	if (ft_strnstr(flags, "ll", 100))
		ft_unsignedlonglongbase(n, "0123456789ABCDEF", 16);
	else if (ft_strnstr(flags, "l", 100))
		ft_unsignedlongbase((unsigned long)n, "0123456789ABCDEF", 16);
	else if (ft_strnstr(flags, "hh", 100))
		ft_unsignedshortshortbase((unsigned char)n, "0123456789ABCDEF", 16);
	else if (ft_strnstr(flags, "h", 100))
		ft_unsignedshortbase((unsigned short)n, "0123456789ABCDEF", 16);
	else
		ft_unsignedbase((unsigned int)n, "0123456789ABCDEF", 16);
}

int	ft_writtenhex(int min, int tern, char *str)
{
	if (min < 0)
		min = -min;
	if (ft_contains(str, '#'))
		min = min + 2;
	free(str);
	if (min >= tern)
		return (min);
	return (tern);
}

int	ft_hexupper(unsigned long long nb, char *str, int min, int max)
{
	int	size;
	int	tern;

	size = ft_unsignedintlenbase(nb, 16, max, str);
	if (ft_contains(str, '#'))
		min = min - 2;
	tern = size;
	if (max > size)
		tern = max;
	if (ft_contains(str, '0') && min > 0 && !ft_contains(str, '.'))
		ft_writexchar(min - tern, '0');
	else if (min > 0)
		ft_writexchar(min - tern, ' ');
	if (ft_contains(str, '#'))
		write(1, "0X", 2);
	if (max > size)
		ft_writexchar((max - size), '0');
	if (nb != 0 || max != 0 || !ft_contains(str, '.'))
		ft_hexupperhub(nb, str);
	if (min < 0)
		ft_writexchar(-min - tern, ' ');
	return (ft_writtenhex(min, tern, str));
}
