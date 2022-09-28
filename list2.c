/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro < dcano-ro@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:08:41 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/09/25 12:09:15 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order(t_node **head)
{
	t_node	*prev;
	t_node	*aux;
	int		swap;

	while (!is_ordered(head))
	{
		aux = *head;
		prev = *head;
		while (aux != NULL)
		{
			if (aux->content < prev->content)
			{
				swap = aux->content;
				aux->content = prev->content;
				prev->content = swap;
			}
			prev = aux;
			aux = aux->next;
		}
	}
}

void	free_list(t_node **head)
{
	t_node	*prev;
	t_node	*aux;

	if (*head != NULL)
	{
		aux = *head;
		while (aux->next != NULL)
		{
			prev = aux;
			aux = aux->next;
			free(prev);
		}
		free(aux);
	}
	free(head);
	head = NULL;
}

void	cambiar_positivo(t_node **original, t_node **ordered)
{
	t_node	*position;
	t_node	*searcher;
	int		i;

	position = *original;
	while (position != NULL)
	{
		i = 1;
		searcher = *ordered;
		while (searcher != NULL)
		{
			if (position->content == searcher->content)
			{
				position->content = i;
				break ;
			}
			searcher = searcher->next;
			i++;
		}
		position = position->next;
	}
	free_list(ordered);
}

void	add_first(t_node **head, int new_elem, t_node **head2)
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
	if (*head == NULL)
		*head = new;
	else
	{
		new->next = *head;
		*head = new;
	}
}

t_node	*delete_node(t_node **head, t_node *n1, t_node *prev)
{
	if (*head == n1)
	{
		*head = n1->next;
		free(n1);
		return (*head);
	}
	else
	{
		prev->next = n1->next;
		free(n1);
		return (prev->next);
	}
}
