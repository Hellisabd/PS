/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:44:33 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/11/20 12:39:30 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "Libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_printnbr(int n);
int		ft_prints(char *s);
int		ft_printp(uintptr_t n);
int		ft_printhexlow(unsigned int n);
int		ft_printhexup(unsigned int n);
int		ft_printchar(int c);
int		ft_printunbr(unsigned int n);
char	*ft_itoa_baseprintf(unsigned int n, int low_or_up);

#endif
