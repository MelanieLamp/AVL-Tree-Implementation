/*
 * Project: AVL Tree Implementation
 * File: Tree.h
 * Author: Melanie Lamp
 * Last Modified: 5/10/2020
* Description: This class creates nodes of generic data types for key and value.
*              Preforms rotations on inserted nodes to rebalance heights in the binary search tree.
*/
#ifndef _TREE_
#define _TREE_
#include <array>
#include <iostream>
template<typename K, typename V>

/*
  * Class: Tree
  * Description: Contains the methods for adding new nodes and also 
  * 			 contains balance and height methods that determine 
  * 			 where the newly generated node will be located. 
  */
class Tree
{
private:
	K key;
	V value;
	Tree *left;
	Tree *right;
	int height;
public:
	Tree(K key, V value)
	{
		this->key = key;
		this->value = value;
	}

	Tree* newNode(K key, V value)
	{
		Tree* node = new Node();
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
		node->height = 1;
		return(node);
	}
	//Determines the greater value.
	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}
	//Returns the height of a node.
	int height(Tree* N)
	{
		if (N == NULL)
		{
			return 0;
		}
		return N->height;
	}
	//Rotates node to the right.
	Tree* rightRotate(Tree* y)
	{
		//Right rotations
		Tree *x = y->left;
		Tree *T2 = x->right;

		x->right = y;
		y->left = T2;

		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;
		return x;
	}
	//Rotates node to the left.
	Tree* leftRotate(Tree* x)
	{
		//Left rotations
		Tree *y = x->right;
		Tree *T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;
		return y;
	}
	//Returns height-balanced AVL
	int getBalance(Tree* N)
	{
		if (N == NULL)
			return 0;
		return height(N->left) - height(N->right);
	}
/*
 * Function: insert
 * Description: Adds the given key-pair value to the given Tree if the value
                does not already exist in the tree and uses rotations to determine
				it's height and location in the tree.
 * Input:
 *     tree - a pointer to the Tree struct object
 *     key - the value to be inserted
 */
	Tree* insert(Tree* node, K key)
	{
		if (node == NULL)
			return (newNode(key));
		if (key < node->key)
			node->left = insert(node->left, key);
		else if (key > node->key)
			node->right = insert(node->right, key);

		node->height = 1 + max(height(node->left), height(node->right));
		int balance = getBalance(node);

		//Left-Left Rebalance
		if (balance > 1 && key < node->left->key)
		{
			return rightRotate(node);
		}

		//Right-Right Rebalance
		if (balance < -1 && key > node->right->key)
		{
			return leftRotate(node);
		}

		//Left-Right Rebalance.
		if (balance > 1 && key > node->left->key)
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		//Right-Left Rebalance
		if (balance < -1 && key < node->right->key)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}
/*
 * Function: inOrderList
 * Description: Creates a dynamic array of all the values in the
 *              given Tree node in sorted order. 
 * Input:
 * 	   int** - double pointer array
 *     tree - a pointer to the Tree struct object
 * Output:
 *     int - returns the count in the list
 */
	void inOrderList(int**arr, Tree* node)
	{
		int count = 0;
		if (node != NULL)
		{
			count = inOrderList(arr, node->left);
			arr[count] = node->value;
			count = count + 1;
			count = inOrderList(arr, node->right);
		}
		return count;
	}
/*
 * Function: list
 * Description: Creates an array of the values size in the
 *              given Tree node.
 * Input:
 *     tree - a pointer to the Tree struct object
 * Output:
 *     returns - array with node size to be used in the 
 * 				 inOrderList method.
 */
	int* list(Tree* node, V value)
	{
		if (node == NULL)
		{
			return 0;
		}
		else
		{
			Array arr[node.size];
			inOrderList(arr, index, 0);
		}
		return arr;
	}
};
#endif
