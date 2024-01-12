/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_both.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:21:38 by bgrosjea          #+#    #+#             */
/*   Updated: 2024/01/11 16:12:29 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	rrr(t_Node **a, t_Node **b, int boul)
{
	rra(a, 0);
	rrb(b, 0);
	if (boul == 1)
		ft_printf("rrr\n");
}

void	ss(t_Node **a, t_Node **b, int boul)
{
	sa(a, 0);
	sb(b, 0);
	if (boul == 1)
		ft_printf("ss\n");
}

void	rr(t_Node **a, t_Node **b, int boul)
{
	ra(a, 0);
	rb(b, 0);
	if (boul == 1)
		ft_printf("rr\n");
}

int	find_min(t_Node *a)
{
	int	min;

	min = 500;
	while (a)
	{
		if (min > a->rank)
			min = a->rank;
		a = a->next;
	}
	return (min);
}

int	ft_find_next_maxrank(t_Node *a, int to_find)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (a)
	{
		if (a->rank == to_find)
			j = i;
		a = a->next;
		i++;
	}
	if (j > i / 2)
		return (-1);
	return (0);
}
