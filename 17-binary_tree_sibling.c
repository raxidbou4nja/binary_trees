#include "binary_trees.h"

/**
 * binary_tree_sibling - to find the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node,
 * or NULL if no sibling or if node is NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return (node->parent->left);
	else
		return (NULL);
}
