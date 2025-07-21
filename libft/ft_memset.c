/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:21:54 by adiehl-b          #+#    #+#             */
/*   Updated: 2024/05/27 15:53:18 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*start;

	if (str == NULL)
		return (NULL);
	start = str;
	while (n != 0)
	{
		*start = c;
		start++;
		n--;
	}
	return (str);
}
