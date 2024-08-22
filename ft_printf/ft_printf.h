/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:16:52 by hdaher            #+#    #+#             */
/*   Updated: 2024/05/30 08:35:20 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Includes //

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

// ft_printf.c //

int		ft_printf(const char *str, ...);
int		put_arg(char format, va_list args, int *count);

// tools_1.c //

void	ft_printnbr_hex(unsigned int nbr, int is_upper, int *count);
void	ft_printnbr(int n, int *count);
void	ft_printunsignednbr(unsigned int n, int *count);
void	ft_printptr_rec(unsigned long nbr, char *base, int *count);
void	ft_printptr(unsigned long ptr, int *count);

// tools_2.c //

void	ft_printchar(char c, int *count);
void	ft_printstr(char *str, int *count);

#endif
