/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:22:29 by adiehl-b          #+#    #+#             */
/*   Updated: 2024/05/31 15:10:43 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n)
	{
		if (c1[i] != c2[i])
			break ;
		if (c1 [i] * c2[i] == 0)
			break ;
		i++;
	}
	return (c1[i] - c2[i]);
}
