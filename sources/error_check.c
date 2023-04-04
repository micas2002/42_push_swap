/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:59:19 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/26 14:42:11 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	long_atoi(const char *str)
{
	long int	x;
	long int	a;
	long int	sinal;

	sinal = 1;
	a = 0;
	x = 0;
	while (str[x] != '\0' && (str[x] == ' ' || str[x] == 12
			|| str[x] == 10 || str[x] == 13 || str[x] == 9 || str[x] == 11))
		x++;
	while (str[x] != '\0' && (str[x] == 43 || str[x] == 45))
	{
		if (str[x + 1] == '+' || str[x + 1] == '-')
			return (0);
		else if (str[x] == '-')
			sinal *= -1;
		x++;
	}
	while (str[x] > 47 && str[x] < 58)
	{
		a = (str[x] - '0') + (a * 10);
		x++;
	}
	return (a * sinal);
}

int	check_duplicate(int argc, long int *x, int i)
{
	int	j;

	j = 1;
	i = 0;
	while (i <= argc - 1)
	{
		j = 1;
		while (j + i < argc - 1)
		{
			if (x[j + i] == x[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_input(int argc, char **argv, long int *x)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_int(argv[i]) == 0)
			return (0);
		x[i - 1] = long_atoi(argv[i]);
		if (x[i - 1] > 2147483647 || x[i - 1] < -2147483648)
			return (0);
		i++;
	}
	if (check_duplicate(argc, x, i) == 0)
		return (0);
	return (1);
}

int	error_check(int argc, char **argv)
{
	long int	*x;

	x = malloc(sizeof(long int) * argc - 1);
	if (!x)
		return (0);
	if (check_input(argc, argv, x) == 0)
	{
		free (x);
		return (0);
	}
	free (x);
	return (1);
}
