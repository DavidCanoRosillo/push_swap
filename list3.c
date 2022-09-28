/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro < dcano-ro@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:04:16 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/09/25 12:11:45 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **head)
{
	t_node	*aux;

	aux = *head;
	if (aux == NULL)
		return ;
	add(head, aux->content);
	*head = aux->next;
	write(1, "ra\n", 3);
	free(aux);
}

void	sb(int *b, int size)
{
	int	swap;
	int	condition;

	if (size == 5)
	{
		swap = b[0];
		b[0] = b[1];
		b[1] = swap;
		condition = !(b[0] == (b[1] + 1) || (b[1] == 5 && b[0] == 1));
		if (condition && (b[0] > b[1]))
			condition = 1;
		else
			condition = 0;
		if (condition || b[1] == (b[0] + 1) || (b[0] == 5 && b[1] == 1))
		{
			swap = b[0];
			b[0] = b[1];
			b[1] = swap;
			write(1, "sb\n", 3);
		}
	}
}

t_node	*new_node(t_node **head, t_node **head2, int new_elem)
{	
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		free_list(head2);
		error(head);
	}
	new->content = new_elem;
	new->next = NULL;
	return (new);
}

void	l(t_node **head, t_node **b, unsigned int bit)
{
	t_node	*prev;
	t_node	*aux;

	aux = *head;
	while (aux != NULL)
	{
		if ((aux->content & bit) != bit)
		{
			add_first(b, aux->content, head);
			aux = delete_node(head, aux, prev);
			write(1, "pb\n", 3);
		}
		else
		{
			prev = aux;
			aux = aux->next;
			write(1, "ra\n", 3);
		}
	}	
}

void	big_stack(t_node **head)
{
	t_node			*aux;
	t_node			**b;
	unsigned int	bit;

	bit = 1;
	while (!is_ordered(head))
	{
		b = malloc(sizeof(t_node *));
		*b = NULL;
		l(head, b, bit);
		aux = *b;
		while (aux != NULL)
		{
			add_first(head, aux->content, b);
			aux = aux->next;
			write(1, "pa\n", 3);
		}
		free_list(b);
		bit = bit << 1;
	}
}
