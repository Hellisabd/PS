/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:41:18 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/20 18:26:27 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    sa(t_Node **a, int boul)//ok
{
	t_Node	*tmp;
	
	tmp = *a;
	if (*a && (*a)->next)
	{
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
	if (boul)
		ft_printf("sa\n");
}

void    ra(t_Node **a, int boul) //ok
{
	t_Node	*tmp;
	
	if (a && (*a)->next && *a)
	{
		tmp = *a;
		*a = (*a)->next;
		ft_lstadd_back(a, tmp);
		if (boul)
			ft_printf("ra\n");
	}
}

void    pa(t_Node **a, t_Node **b) //ok
{
	t_Node	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, tmp);
	ft_printf("pa\n");
}

void    rra(t_Node **a, int boul) //ok
{
	t_Node	*current;
	t_Node	*secondlast;
	t_Node	*last;


	current = *a;
	if (a && *a && (*a)->next)
	{
		while (current)
		{
			secondlast = last;
			last = current;
			current = current->next;
		}
		if (secondlast)
			secondlast->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (boul)
		ft_printf("rra\n");
}