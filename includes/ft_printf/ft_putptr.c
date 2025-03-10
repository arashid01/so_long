/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrashid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:34:17 by amrashid          #+#    #+#             */
/*   Updated: 2024/09/30 23:05:18 by amrashid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				length;

	length = 0;
	address = (unsigned long)ptr;
	if (address == 0)
		return (ft_putstr("(nil)"));
	else
		length += ft_putstr("0x");
	length += ft_puthex(address, 0);
	return (length);
}
