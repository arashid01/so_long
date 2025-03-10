/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:33:15 by amrashid          #+#    #+#             */
/*   Updated: 2024/09/30 22:35:16 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	num;
	int		len;

	num = nb;
	len = 0;
	if (num < 0)
	{
		len++;
		ft_putchar('-');
		num = -num;
	}
	if (num / 10 != 0)
	{
		len += ft_putnbr(num / 10);
	}
	len += ft_putchar(num % 10 + 48);
	return (len);
}
