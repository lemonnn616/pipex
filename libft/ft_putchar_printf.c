/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:03:25 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/10 16:19:38 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_printf(t_fmt *fmt)
{
	const char	c = va_arg(fmt->args, int);

	if (fmt->width > fmt->precision)
		fmt->offset = fmt->width - 1;
	fmt->len += fmt->offset + 1;
	if (fmt->minus)
	{
		ft_putchar_fd(c, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
}
