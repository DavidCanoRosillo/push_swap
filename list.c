/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro < dcano-ro@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:06:13 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/09/25 12:12:34 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add(t_node **head, int new_elem)
{
	t_node	*last;
	t_node	*new;

	last = *head;
	new = malloc(sizeof(t_node));
	if (!new)
		error(head);
	new->content = new_elem;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

t_node	*copy2(t_node **head, t_node **copy, t_node *aux, int new_elem)
{
	t_node	*new;
	t_node	*node;

	new = malloc(sizeof(t_node));
	if (new == NULL)
	{
		node = *copy;
		while (node != NULL)
		{
			aux = node;
			node = node->next;
			free(aux);
		}
		error(head);
	}
	new->content = new_elem;
	new->next = NULL;
	return (new);
}

t_node	**copy(t_node **head, t_node *last)
{
	t_node	**copy;
	t_node	*aux;
	t_node	*new;

	copy = malloc(sizeof(t_node *));
	if (copy == NULL)
		error(head);
	*copy = NULL;
	while (last != NULL)
	{
		new = copy2(head, copy, aux, last->content);
		if (*copy == NULL)
		{
			*copy = new;
			aux = new;
		}
		else
		{
			aux->next = new;
			aux = aux->next;
		}
		last = last->next;
	}
	return (copy);
}

int	is_ordered(t_node **head)
{
	int		last;
	t_node	*aux;

	last = -2147483648;
	aux = *head;
	while (aux != NULL)
	{
		if (last > aux->content)
			return (0);
		last = aux->content;
		aux = aux->next;
	}
	return (1);
}
