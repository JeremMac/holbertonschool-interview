#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - a function that insert a node in
 * a linked list.
 * @head: a pointer to the head of a list.
 * @number: an int variable to assign to the node.
 * Return: the created node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode;
	listint_t *currentNode = *head;

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
	{
		return (NULL);
	}
	newNode->n = number;
	newNode->next = NULL;
	while (currentNode != NULL)
	{
		if (currentNode->n < number && currentNode->next->n >= number)
		{
			newNode->next = currentNode->next;
			currentNode->next = newNode;
			return (newNode);
		}
		currentNode = currentNode->next;
	}
	return (NULL);
}
