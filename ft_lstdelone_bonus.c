/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosorio- <dosorio-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:40:23 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/03 16:42:14 by dosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	libera(void *content)
{
	free(content);
}
/* int main(void)
{
	t_list *n = ft_lstnew(strdup("Olá"));
	ft_lstdelone(n, libera);
	return (0);
} */