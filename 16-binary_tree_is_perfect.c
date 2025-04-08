#include "binary_trees.h"

/**
	* find_depth - Finds the depth (number of edges) in the leftmost branch.
	* @node: Pointer to the root node of the tree.
	*
	* Return: Depth of the leftmost leaf.
	*/
static int find_depth(const binary_tree_t *node)
{
	int d = 0;

	while (node != NULL && node->left != NULL)
	{
		d++;
		node = node->left;
	}
	return (d);
}

/**
	* perfect_helper - Recursively checks if a binary tree is perfect.
	* @tree: Pointer to the current node.
	* @level: Current level in the tree (root is level 0).
	* @expected_depth: Expected level for all leaves.
	*
	* Return: 1 if the subtree is perfect, 0 otherwise.
	*/
static int perfect_helper(const binary_tree_t *tree, int level, int expected_depth)
{
	if (tree->left == NULL && tree->right == NULL)
		return (level == expected_depth);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (perfect_helper(tree->left, level + 1, expected_depth) &&
		perfect_helper(tree->right, level + 1, expected_depth));
}

/**
	* binary_tree_is_perfect - Checks if a binary tree is perfect.
	* @tree: Pointer to the root node of the tree to check.
	*
	* Return: 1 if tree is perfect, 0 otherwise.
	*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int expected_depth;

	if (tree == NULL)
		return (0);
	expected_depth = find_depth(tree);
	return (perfect_helper(tree, 0, expected_depth));
}
