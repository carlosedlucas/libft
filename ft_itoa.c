/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosed <carlosed@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:17:06 by carlosed          #+#    #+#             */
/*   Updated: 2021/08/10 18:21:27 by carlosed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts the integer `num` into the string `str`.
 *
 * @param str Pointer to the string to allocate `num`
 * @param size Buffer size to allocate the string
 * @param num Integer to be converted to string
 * @param is_negative If `num` is negative
 * @return char* Returns the integer `num` as a string with
 * NULL-terminated byte.
 */
static char	*convert_itoa(char *str,
						  size_t size,
						  unsigned int num,
						  unsigned int is_negative)
{
	str[size] = '\0';
	while (size--)
	{
		str[size] = (num % 10) + 48;
		num /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

/**
 * @brief Returns the length of `num` to allow the
 * conversion of `num` integer to a string.
 *
 * @param num The integer to analyse
 * @return size_t Returns the buffer size to allocate `num`
 * as a string. If `num` is negative, returns length + 1 to
 * also allocate the negative sign.
 */
size_t	ft_numlen(int num)
{
	size_t	len;

	len = 1;
	if (num < 0)
		len++;
	num /= 10;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t			n_digits;
	unsigned int	is_negative;
	char			*str;

	n_digits = ft_numlen(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	str = malloc(sizeof(char) * (n_digits + 1));
	if (str == NULL)
		return (NULL);
	return (convert_itoa(str, n_digits, (unsigned int)n, is_negative));
}
