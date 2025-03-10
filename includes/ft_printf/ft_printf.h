/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amal <amal@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:24:03 by amrashid          #+#    #+#             */
/*   Updated: 2025/01/25 05:54:51 by amal             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_puthex(unsigned long num, int hexcase);
int	ft_putptr(void *ptr);
int	ft_putnbr(int nb);
int	ft_uint(unsigned int nb);
int	ft_printf(const char *format, ...);

#endif
