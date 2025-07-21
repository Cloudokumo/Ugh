/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:22:35 by adiehl-b          #+#    #+#             */
/*   Updated: 2024/05/27 16:27:34 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			ret = (char *)(s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		ret = (char *)(s + i);
	return (ret);
}
