/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:13:01 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/11/02 18:34:08 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*begin;
	void	*e;

	if (!lst || !del || !f)
		return (NULL);
	tmp = lst;
	begin = NULL;
	while (tmp)
	{
		e = f(tmp->content);
		new = ft_lstnew(e);
		if (!new)
		{
			del(e);
			ft_lstdelone(new, del);
			ft_lstclear(&begin, del);
			return (begin);
		}
		ft_lstadd_back(&begin, new);
		tmp = tmp->next;
	}
	return (begin);
}
