/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:22:25 by adiehl-b          #+#    #+#             */
/*   Updated: 2024/05/24 14:47:07 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	s;
	size_t	len_dest;
	size_t	len_src;

	len_dest = 0;
	while (dest[len_dest] != '\0')
		len_dest++;
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (size <= len_dest)
		return (len_src + size);
	else
	{
		s = 0;
		while (src[s] != '\0' && (len_dest + s) < size - 1)
		{
			dest[len_dest + s] = src[s];
			s++;
		}
	}
	dest[len_dest + s] = '\0';
	return (len_dest + len_src);
}
