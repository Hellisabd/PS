/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_both.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:21:38 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/14 14:47:51 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    rrr(t_Node **a, t_Node **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}

void    ss(t_Node **a, t_Node **b)
{
	sa(*a, 0);
	sb(*b, 0);
	ft_printf("ss\n");
}

void    rr(t_Node **a, t_Node **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}
