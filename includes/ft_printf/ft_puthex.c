/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:33:26 by amrashid          #+#    #+#             */
/*   Updated: 2024/09/30 22:33:28 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long num, int hexcase)
{
	int	length;

	length = 0;
	if (num >= 16)
		length += ft_puthex((num / 16), hexcase);
	if (num % 16 < 10)
		length += ft_putchar('0' + (num % 16));
	else
	{
		if (hexcase)
			length += ft_putchar('A' + (num % 16) - 10);
		else
			length += ft_putchar('a' + (num % 16) - 10);
	}
	return (length);
}
