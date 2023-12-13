/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:41:54 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/13 18:53:21 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define	PS_H

# include "./Libft/libft.h"

void	ft_error(int argc, char **argv);
void    sa(t_Node *a);
void    ra(t_Node **a);
void    pa(t_Node *a, t_Node **b);
void    rra(t_Node **a);
void    pa(t_Node *a, t_Node **b);
void    pb(t_Node *b, t_Node **a);
#endif
