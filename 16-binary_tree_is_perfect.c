#include "binary_trees.h"


/**
 * binary_tree_height - to measure the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	left_height = (tree->left) ? 1 + binary_tree_height(tree->left) : 0;
	right_height = (tree->right) ? 1 + binary_tree_height(tree->right) : 0;

	return ((left_height > right_height) ? left_height : right_height);
}


/**
 * binary_tree_is_leaf - to check if a node is a leaf
 * @node: Pointer to the node to check
 * Return: return 1 if node is a leaf, otherwise return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	else
		return (0);
}


/**
 * binary_tree_is_perfect - to check if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int right = 0;
	int left = 0;

	if (!tree)
	{
		return (0);
	}

	if (binary_tree_is_leaf(tree))
	{
		return (1);
	}

	if (!tree->right || !tree->left)
	{
		return (0);
	}

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left == right)
	{
		if (binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right))
		{
			return (1);
		}
	}

	return (0);
}
