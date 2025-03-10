/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:33:38 by amrashid          #+#    #+#             */
/*   Updated: 2024/09/30 22:36:42 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uint(unsigned int nb)
{
	unsigned long	num;
	int				len;

	len = 0;
	num = nb;
	if (num >= 10)
		len += ft_uint(num / 10);
	len += ft_putchar((num % 10) + '0');
	return (len);
}
