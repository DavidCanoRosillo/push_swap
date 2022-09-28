/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro < dcano-ro@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:10:45 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/09/25 12:09:47 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	eval(t_node *aux, int bi, int size)
{
	return ((aux->content == 1 && bi == 4) && (size == 4));
}

int	error_or_added(char *new, t_node **head)
{
	long	result;

	if (!is_digit(new))
		error(head);
	result = ft_atoi(new);
	if (result < -2147483648 || result > 2147483647)
		error(head);
	if (is_duplicate(head, result))
		error(head);
	add(head, (int) result);
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	**head;
	t_node	**head2;

	if (argc > 1)
	{
		head = parse(argc, argv);
		head2 = copy(head, *head);
		order(head2);
		cambiar_positivo(head, head2);
		ordena_stack(head);
		free_list(head);
	}
	return (0);
}
