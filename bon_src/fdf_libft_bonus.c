/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_libft_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:09:25 by jiko              #+#    #+#             */
/*   Updated: 2023/09/25 20:31:52 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 && *s2)
	{
		idx++;
		if (idx + 1 > n)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen((char *)src));
	while (i < dstsize - 1 && *(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen((char *)src));
}

int	ft_atoi(char *str)
{
	long long	numminus;
	long long	num;

	numminus = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			numminus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)(numminus * num));
}

int	hex_to_dex(char *hex)
{
	int	ret;

	ret = 0;
	while (*hex)
	{
		if (*hex >= '0' && *hex <= '9')
			ret = ret * 16 + (*hex - '0');
		else if (*hex >= 'a' && *hex <= 'f')
			ret = ret * 16 + (*hex - 'a' + 10);
		else if (*hex >= 'A' && *hex <= 'F')
			ret = ret * 16 + (*hex - 'A' + 10);
		hex++;
	}
	return (ret);
}
