/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:28 by mibernar          #+#    #+#             */
/*   Updated: 2023/04/04 17:33:50 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_u(int args)
{
	int		a;
	char	*str;

	a = args;
	if (a < 0)
		a = 4294967296 + a;
	str = ft_unsigned_itoa(a);
	a = ft_strlen(str);
	write (1, str, a);
	free (str);
	return (a);
}
