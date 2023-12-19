/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:41:54 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/19 17:14:34 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define	PS_H

# include "./Libft/libft.h"


typedef struct stock
{
	int				cost;
	int				cost2;
	int				best_cost;
}	t_stock;


void	ft_error(int argc, char **argv);
void    ft_check(int argc, char **argv);
int     ft_check_cost_diff(int cost, int cost2);
void	get_right_pos_pos(t_stock *costs, t_Node **src, t_Node **dest);
void	ft_get_node_b(t_Node **src, t_Node **find_target, int size);
int	    ft_get_Ntop(int N_to_p, t_Node *a, int argc, int node_pos);
void	get_right_pos_utils(t_stock *costs, t_Node **src, t_Node **dest);
void    sa(t_Node *a, int boul);
void	get_right_pos_neg(t_stock *costs, t_Node **src, t_Node **dest);
int	    find_best_cost(t_Node *a, t_stock *costs);
void    ra(t_Node **a, int boul);
int		ft_check_same(t_Node **a, int size);
int		ft_get_target_cost(int nbr, t_Node *find_target, int size);
void    rra(t_Node **a, int boul);
t_Node	**ft_sort_three(t_Node **a);
bool	a_is_sorted(t_Node *a);
void    pa(t_Node **a, t_Node **b);
void    sb(t_Node *b, int boul);
void    rb(t_Node **b, int boul);
void    pb(t_Node **b, t_Node **a);
void    rrb(t_Node **b, int boul);
void    rr(t_Node **a, t_Node **b);
void    ss(t_Node **a, t_Node **b);
void    rrr(t_Node **a, t_Node **b);
void	ft_sort(t_Node **a, int argc);
int	ft_get_target_cost_b(int nbr, t_Node *find_target, int size);
int	find_min(t_Node *find_target);
void	get_right_pos_neg_b(t_stock *costs, t_Node **src, t_Node **dest);
void	get_right_pos_pos_b(t_stock *costs, t_Node **src, t_Node **dest);
void	get_right_pos_utils_b(t_stock *costs, t_Node **src, t_Node **dest);

#endif
