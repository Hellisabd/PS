/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:41:18 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/13 19:18:21 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    sa(t_Node *a)//ok
{
	int	tmp;
	if (a && a->next)
	{
		tmp = a->next->nbr;
		a->next->nbr = a->nbr;
		a->nbr = tmp;
	}
}

void    ra(t_Node **a) //ok
{
	t_Node	*tmp;
	
	if (a && (*a)->next && *a)
	{
		tmp = *a;
		*a = (*a)->next;
		ft_lstadd_back(a, tmp);
	}
}

void    pa(t_Node *a, t_Node **b)
{
	t_Node	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	ft_lstadd_front(&a, tmp);
}

void    rra(t_Node **a)
{
	t_Node	*current;
	t_Node	*secondlast;
	t_Node	*last;


	current = *a;
	if (a && *a && (*a)->next)
	{
		while (current->next)
		{
			secondlast = last;
			last = current;
			current = current->next;
		}
		if (secondlast)
			secondlast->next = NULL;
		current->next = *a;
		*a = current;
	}
}