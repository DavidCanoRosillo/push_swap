/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errores.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro < dcano-ro@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:31:19 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/09/25 12:12:52 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 0;
	number = 0;
	while (str[i])
	{
		if ((str[i] > '9' || str[i] < '0') && str[i] != '+' && str[i] != '-')
			return (0);
		if (str[i] <= '9' && str[i] >= '0')
			number = 1;
		if (str[i] == '+' || str[i] == '-')
		{
			if (sign == 1)
				return (0);
			sign = 1;
		}
		i++;
	}
	if (i > 13)
		return (0);
	return (number);
}

long	ft_atoi(const char *str)
{
	int						i;
	int						signo;
	unsigned long long int	n;

	i = 0;
	n = 0;
	signo = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signo = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
		n = n * 10 + (str[i++] - 48);
	if (n > 9223372036854775807 && signo < 0)
		return (0);
	else if (n > 9223372036854775807 && signo > 0)
		return (-1);
	return ((long) n * signo);
}

int	is_duplicate(t_node **head, int elem)
{
	t_node	*last;

	last = *head;
	while (last != NULL)
	{
		if (last->content == elem)
			return (1);
		last = last->next;
	}
	return (0);
}
