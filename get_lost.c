/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:12:36 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/19 17:29:22 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	get_right_pos_utils_b(t_stock *costs, t_Node **src, t_Node **dest)
{
	if (costs->cost <= 0 && costs->cost2 >= 0)
	{
		while (costs->cost != 0)
		{
			rrb(src, 1);
			costs->cost++;
		}
		while (costs->cost2 != 0)
		{
			ra(dest, 1);
			costs->cost2--;
		}
	}
	else
	{
		while (costs->cost != 0)
		{
			rb(src, 1);
			costs->cost--;
		}
		while (costs->cost2 != 0)
		{
			rra(dest, 1);
			costs->cost2++;
		}
	}
}

void	get_right_pos_pos_b(t_stock *costs, t_Node **src, t_Node **dest)
{
	if (costs->cost > 0 && costs->cost2 > 0)
	{
		while (costs->cost != 0 && costs->cost2 != 0)
		{
			costs->cost--;
			costs->cost2--;
			rr(src, dest);
		}
		if (costs->cost == 0)
		{
			while (costs->cost2-- != 0)
				rra(dest, 1);
		}
		if (costs->cost2 == 0)
		{
			while (costs->cost-- != 0)
				rrb(dest, 1);
		}
	}
	get_right_pos_utils_b(costs, src, dest);
}

void	get_right_pos_neg_b(t_stock *costs, t_Node **src, t_Node **dest)
{
	if (costs->cost < 0 && costs->cost2 < 0)
	{
		while (costs->cost != 0 && costs->cost2 != 0)
		{
			costs->cost++;
			costs->cost2++;
			rrr(src, dest);
		}
		if (costs->cost == 0)
		{
			while (costs->cost2++ != 0)
				rra(dest, 1);
		}
		if (costs->cost2 == 0)
		{
			while (costs->cost++ != 0)
				rrb(dest, 1);
		}
	}
	else
		get_right_pos_pos_b(costs, src, dest);
}