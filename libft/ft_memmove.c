/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:21:50 by adiehl-b          #+#    #+#             */
/*   Updated: 2024/05/27 16:44:41 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n )
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		while (i < n)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	else
	{
		i = i - 1;
		while (++i < n)
			ptr1[n - i - 1] = ptr2[n - i - 1];
	}
	return (dest);
}
