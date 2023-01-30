/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:47:08 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/22 21:42:53 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void del(void *content)
{
	free(content);
}

void *f(void *content)
{
	content = "xxxx";
	printf("%s\n", content);
	return(content);

}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*new;

	curr = 0;
	new = 0;
	while (lst != NULL)
	{
		curr = ft_lstnew(f(lst->content));
		if (!curr)
		{
			ft_lstclear(&curr, del);
			return (0);
		}
		ft_lstadd_back(&new, curr);
		lst = lst->next;
	}
	return (new);
}
