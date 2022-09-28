/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro < dcano-ro@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:28:10 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/09/25 12:09:24 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_3(t_node **head)
{
	t_node	*aux;
	int		code;

	code = 0;
	aux = *head;
	while (aux != NULL)
	{
		code += aux->content;
		code = code * 10;
		aux = aux->next;
	}
	if (code == 210)
		write(1, "ra\n", 3);
	if (code == 1320)
		write(1, "rra\nsa\n", 7);
	if (code == 2130)
		write(1, "sa\n", 3);
	if (code == 2310)
		write(1, "rra\n", 4);
	if (code == 3120)
		write(1, "ra\n", 3);
	if (code == 3210)
		write(1, "sa\nrra\n", 7);
	order(head);
}

void	transform_3(t_node **head)
{
	t_node	**head2;

	head2 = copy(head, *head);
	order(head2);
	cambiar_positivo(head, head2);
	stack_3(head);
}

void	re_stack(t_node **head, int *b, int size)
{
	int		times;
	int		i;
	t_node	*aux;
	int		c;

	times = 1 + (size == 5);
	i = 0;
	sb(b, size);
	while (i < times)
	{
		aux = *head;
		c = eval(aux, b[i], size);
		if (aux->content == (b[i] + 1) || (aux->content == 1 && b[i] == 5) || c)
		{
			add_first(head, b[i++], NULL);
			write(1, "pa\n", 3);
		}
		else
			ra(head);
	}
	while (!is_ordered(head))
		ra(head);
	free(b);
}

void	stack_5(t_node **head, int size)
{
	t_node	**a_copy;
	int		*arr;

	if (!is_ordered(head))
	{
		arr = malloc(sizeof(int) * 2);
		if (!arr)
			error(head);
		arr[0] = (*head)->content;
		delete_node(head, *head, NULL);
		write(1, "pb\n", 3);
		if (size == 5)
		{
			arr[1] = (*head)->content;
			delete_node(head, *head, NULL);
			write(1, "pb\n", 3);
		}
		a_copy = copy(head, *head);
		order(a_copy);
		transform_3(head);
		re_stack(a_copy, arr, size);
		free_list(a_copy);
	}
}

void	ordena_stack(t_node **head)
{
	t_node	*aux;
	int		i;

	aux = *head;
	i = 0;
	while (aux != NULL)
	{
		aux = aux->next;
		i++;
	}
	if (i <= 3)
		return (stack_3(head));
	if (i <= 5)
		return (stack_5(head, i));
	if (i > 5)
		return (big_stack(head));
}
