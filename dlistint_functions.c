#include "monty.h"

/**
 * add_dnodeint - Adds a new node at the beggining of a doubly linked list
 * @head: Pointer to the pointer to the head of the list
 * @n: Value to be added to the new node
 *
 * Return: The address of the new element or Null of it fails
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	*head = new_node;

	return (new_node);
}

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list
 * @head: Pointer to the pointer to the head of the list
 * @n: Value to be added to the new node
 *
 * Return: The address of the new element or Null of it fails
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));
	dlistint_t *last = *head;

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = new_node;
	new_node->prev = last;

	return (new_node);
}

/**
 * free_dlistint - Frees the doubly linked list
 * @head: Pointer to the head of the list
 *
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	dlistint_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * delete_dnodeint_at_index - Deletes a node at a given position
 * in the doubly linked list
 * @head: Pointer to a pointer to the head of the list
 * @index: Index of node to be deleted
 *
 * Return: 1 if succeeded else -1 if failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(current);
		return (1);
	}
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
		return (-1);
	if (current->next != NULL)
		current->next->prev = current->prev;
	if (current->prev != NULL)
		current->prev->next = current->next;
	else
		*head = current->next;

	free(current);

	return (1);
}

/**
 * print_dlistint - prints all the elements of a doubly linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list
 */

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t count_node = 0;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		count_node++;
	}

	return (count_node);
}
