/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:41:59 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/14 20:06:14 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_get_Ntop(int N_to_p, t_Node **a, int argc)
{
	int	i;

	i = 0;
	while (N_to_p != (*a)->nbr)
	{
		if (N_to_p == (*a)->nbr)
		{
			if (i < argc / 2)
				return (i * (-1));
			else
				return (i);
		}
		*a = (*a)->next;
		i++;
	}
	return (0);
}

int	ft_getmax(t_Node **a)
{
	int		max;
	t_Node	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (max < tmp->nbr)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_sort(t_Node **a, int size)
{
	t_Node	*b;
	int		N_to_p;

	b = NULL;
	while (*a)
	{
		N_to_p = ft_getmax(a);
		N_to_p = ft_get_Ntop(N_to_p, a, size);
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
	}
	while (b)
		pa(a, &b);
}
