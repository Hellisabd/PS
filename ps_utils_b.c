/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:41:18 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/13 19:05:04 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"


// void    sb(t_Node b)
// {
    
// }

// void    rb(t_Node b)
// {
    
// }
// 
void    pb(t_Node *b, t_Node **a)
{
	t_Node	*tmp;

	tmp = *a;
	*a = (*a)->next;
	ft_lstadd_front(&b, tmp);
}

// void    rrb(t_Node b)
// {
    
// }
