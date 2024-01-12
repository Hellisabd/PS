/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:41:18 by bgrosjea          #+#    #+#             */
/*   Updated: 2024/01/11 17:05:01 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sa(t_Node **a, int boul)
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

void	ra(t_Node **a, int boul)
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

void	pa(t_Node **a, t_Node **b, int boul)
{
	t_Node	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, tmp);
	if (boul == 1)
		ft_printf("pa\n");
}

void	rra(t_Node **a, int boul)
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

int	ft_find_rank_prec(int to_find, t_Node *a)
{
	int	i;
	int	j;
	int	best_rank;

	j = 0;
	i = 0;
	best_rank = 500;
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->rank >= to_find && a->rank < best_rank)
		{
			best_rank = a->rank;
			i = j;
		}
		a = a->next;
		j++;
	}
	if (i > j / 2)
		return (i * -1);
	return (i);
}
