/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:37:39 by adiehl-b          #+#    #+#             */
/*   Updated: 2024/05/31 16:26:39 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*ptr;

	ptr = *lst;
	if (lst == 0 || del == 0)
		return ;
	while (ptr)
	{
		temp = (ptr)->next;
		(*del)(ptr->content);
		free(ptr);
		ptr = temp;
	}
	*lst = NULL;
}
