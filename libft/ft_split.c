/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:04:15 by adiehl-b          #+#    #+#             */
/*   Updated: 2024/05/31 15:09:36 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int	nb_words;
	int	i;

	nb_words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] != c)
			nb_words++;
		else if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			nb_words++;
		i++;
	}
	return (nb_words);
}

static int	ft_len_words(const char *str, char c)
{
	int	i;
	int	len_words;

	len_words = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		len_words++;
		i++;
	}
	return (len_words);
}

static char	*ft_copy_line(const char **str, char c)
{
	char	*line;
	int		len_words;

	while (**str == c)
		++(*str);
	len_words = ft_len_words(*str, c);
	line = (char *)malloc((len_words + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, *str, len_words + 1);
	*str += len_words;
	return (line);
}

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		nb_words;
	char	**output;

	if (str == NULL)
		return (NULL);
	nb_words = ft_count_words(str, c);
	output = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (output != NULL)
	{
		i = 0;
		output[nb_words] = NULL;
		while (i < nb_words)
		{
			output[i] = ft_copy_line(&str, c);
			if (output[i] == NULL)
			{
				ft_free(output);
				output = NULL;
				break ;
			}
			i++;
		}
	}
	return (output);
}
