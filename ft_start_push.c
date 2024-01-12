/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:39:19 by bgrosjea          #+#    #+#             */
/*   Updated: 2024/01/11 19:20:24 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "Libft/libft.h"

void	ft_free_stack(t_Node *a)
{
	t_Node	*tmp;

	while (a)
	{
		tmp = a->next;
		free (a);
		a = tmp;
	}
}

int	ft_fill_node(t_Node **a, char **argv, int i)
{
	ssize_t		number;
	t_Node		*new;

	number = ft_atoi(argv[i]);
	if (number > INT_MAX || number < INT_MIN)
	{
		ft_printf("Error\n");
		ft_lstclear(a);
		exit (EXIT_FAILURE);
	}
	new = ft_lstnew(number);
	if (!new)
	{
		ft_lstclear(a);
		exit (EXIT_FAILURE);
	}
	ft_lstadd_back(a, new);
	return (i + 1);
}

t_Node	*ft_fill_a(t_Node *a, int argc, char **argv)
{
	int		i;
	char	**tmp;
	int		j;
	int		words;

	a = NULL;
	i = 1;
	tmp = NULL;
	while (argc > i)
	{
		words = count_words(argv[i], ' ');
		if (1 == words)
			i = ft_fill_node(&a, argv, i);
		else
		{
			j = 0;
			tmp = ft_split(argv[i], ' ');
			if (!tmp)
				exit((ft_lstclear(&a), 1));
			while (j < words)
				j = ft_fill_node(&a, tmp, j);
			i++;
		}
	}
	return (ft_free_double_tab(tmp), a);
}

bool	ft_check_back(t_Node *a)
{
	t_Node	*tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	if ((tmp->rank) < (a->rank))
		return (true);
	return (false);
}
