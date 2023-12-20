/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:41:18 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/14 15:21:15 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"


void    sb(t_Node *b, int boul)//ok
{
	int	tmp;
	if (b && b->next)
	{
		tmp = b->next->nbr;
		b->next->nbr = b->nbr;
		b->nbr = tmp;
		if (boul)
			ft_printf("sb\n");
	}
}
void    rb(t_Node **b, int boul) //ok
{
	t_Node	*tmp;
	
	if (b && (*b)->next && *b)
	{
		tmp = *b;
		*b = (*b)->next;
		ft_lstadd_back(b, tmp);
		if (boul)
			ft_printf("rb\n");
	}
}
void    pb(t_Node **b, t_Node **a)
{
	t_Node	*tmp;

	if (!a || !(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, tmp);
	ft_printf("pb\n");
}

void    rrb(t_Node **b, int boul) //ok
{
	t_Node	*current;
	t_Node	*secondlast;
	t_Node	*last;


	current = *b;
	if (b && *b && (*b)->next)
	{
		while (current)
		{
			secondlast = last;
			last = current;
			current = current->next;
		}
		if (secondlast)
			secondlast->next = NULL;
		last->next = *b;
		*b = last;
		if (boul)
			ft_printf("rrb\n");
	}
}
