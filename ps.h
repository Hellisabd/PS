/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:41:54 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/14 20:10:02 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define	PS_H

# include "./Libft/libft.h"

void	ft_error(int argc, char **argv);
void    ft_check(int argc, char **argv);
void    sa(t_Node *a, int boul);
void    ra(t_Node **a, int boul);
int		ft_check_same(t_Node **a, int size);
void    rra(t_Node **a, int boul);
void    pa(t_Node **a, t_Node **b);
void    sb(t_Node *b, int boul);
void    rb(t_Node **b, int boul);
void    pb(t_Node **b, t_Node **a);
void    rrb(t_Node **b, int boul);
void    rr(t_Node **a, t_Node **b);
void    ss(t_Node **a, t_Node **b);
void    rrr(t_Node **a, t_Node **b);
void	ft_sort(t_Node **a, int argc);

#endif
