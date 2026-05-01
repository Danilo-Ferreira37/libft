/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosorio- <dosorio-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:16:38 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/03 16:41:56 by dosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while ((*lst) != NULL)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
/* void libera(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *lst = ft_lstnew(strdup("um"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("dois")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("três")));

	ft_lstclear(&lst, libera);

	return (0);
} */