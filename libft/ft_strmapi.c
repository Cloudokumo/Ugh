/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:06:09 by adiehl-b          #+#    #+#             */
/*   Updated: 2024/05/27 15:19:31 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*c;

	i = 0;
	if (!s || (!s && !f))
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	c = ft_strdup(s);
	if (!c)
		return (c = NULL);
	while (s[i])
	{
		c[i] = (*f)(i, s[i]);
		i++;
	}
	return (c);
}
