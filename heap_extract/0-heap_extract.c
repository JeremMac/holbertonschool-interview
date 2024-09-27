#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_down - Ensures the heap property is maintained after extraction.
 * @node: Pointer to the root of the subtree.
 */
void heapify_down(heap_t *node)
{
    heap_t *largest = node;
    heap_t *left = node->left;
    heap_t *right = node->right;

    if (left && left->n > largest->n)
        largest = left;
    if (right && right->n > largest->n)
        largest = right;

    if (largest != node)
    {
        int temp = node->n;
        node->n = largest->n;
        largest->n = temp;
        heapify_down(largest);
    }
}

/**
 * heap_last_node - Gets the last node in level-order traversal.
 * @root: Pointer to the root of the heap.
 *
 * Return: Pointer to the last node.
 */
heap_t *heap_last_node(heap_t *root)
{
    if (!root->left && !root->right)
        return (root);

    if (!root->right)
        return (root->left);

    return (heap_last_node(root->right));
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
    int extracted_value;
    heap_t *last_node, *temp_root;

    if (!root || !*root)
        return (0);

    extracted_value = (*root)->n;
    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (extracted_value);
    }

    last_node = heap_last_node(*root);
    temp_root = *root;
    
    temp_root->n = last_node->n;  // Replace root value with last node value
    if (last_node->parent->right == last_node)
        last_node->parent->right = NULL;
    else
        last_node->parent->left = NULL;

    free(last_node);

    heapify_down(temp_root);  // Restore heap property

    return (extracted_value);
}
