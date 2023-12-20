/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:41:18 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/14 19:53:53 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    sa(t_Node *a, int boul)//ok
{
	int	tmp;
	if (a && a->next)
	{
		tmp = a->next->nbr;
		a->next->nbr = a->nbr;
		a->nbr = tmp;
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