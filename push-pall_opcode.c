#include "monty.h"

/**
 * push - pushes the value onto the stack
 * @stack: pointer to a pointer to a stack
 * @value: value to be pushes onto the stack
 * @line_number: opcode line number
 *
 * Return: void
 */

void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node = add_dnodeint(stack, value);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * push - prints all the values in the stack
 * @stack: pointer to a pointer to a stack
 * @line_number: opcode line number
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	size_t node_count = print_dlistint(*stack);
}
