/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:41:59 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/18 14:00:12 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_get_Ntop(int N_to_p, t_Node *a, int argc)
{
	int	i;

	i = 0;
	while (N_to_p != a->nbr)
	{
		a = a->next;
		i++;
	}
	if (N_to_p == a->nbr)
	{
		if (i > argc / 2)
			return (i - argc + 1);
		else
			return (i);
	}
	return (i);
}

int	ft_getmin(t_Node **a)
{
	int		min;
	t_Node	*tmp;

	tmp = *a;
	min = INT_MAX;
	while (tmp)
	{
		if (min > tmp->nbr)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_sort(t_Node **a, int argc)
{
	t_Node	*b;
	int		N_to_p;

	b = NULL;
	while (*a)
	{
		argc = argc / 6;
		while (argc > 0)
		{
		N_to_p = ft_getmin(a);
		N_to_p = ft_get_Ntop(N_to_p, *a, argc);
			while (N_to_p != 0)
			{
			if (N_to_p < 0)
			{
				rra(a, 1);
				N_to_p++;
			}
			else
			{
				ra(a, 1);
				N_to_p--;
			}
			}
		pb(&b, a);
		argc--;
		}
	}
	while (b)
		pa(a, &b);
}
