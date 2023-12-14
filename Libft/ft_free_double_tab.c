/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:52:12 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/14 13:58:41 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_free_double_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
    {
        free (tab[i]);
        i++;
    }
    free (tab);
}