/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosorio- <dosorio-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:49:14 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/03 16:22:09 by dosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/* int main(void)
{
    t_list *lst = NULL;

    ft_lstadd_back(&lst, ft_lstnew("um"));
    ft_lstadd_back(&lst, ft_lstnew("dois"));
    ft_lstadd_back(&lst, ft_lstnew("três"));

    while (lst)
    {
        printf("%s\n", (char *)lst->content);
        lst = lst->next;
    }

    return 0;
} */