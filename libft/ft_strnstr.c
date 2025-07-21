/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:23:46 by adiehl-b          #+#    #+#             */
/*   Updated: 2024/05/24 14:47:15 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	if (!s || !n)
		return (NULL);
	if (!n || !n[0])
		return ((char *)s);
	i = 0;
	while (s[i] && i < len)
	{
		j = 0;
		while (s[i + j] && n[j]
			&& i + j < len && s[i + j] == n[j])
			j++;
		if (!n[j])
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
