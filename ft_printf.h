/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 06:07:30 by letnitan          #+#    #+#             */
/*   Updated: 2022/12/29 10:31:48 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *mandatory_argument, ...);
int	ft_putstr(char	*str);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	checkflag(va_list args, const char c);
#endif