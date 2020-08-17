/*
 * Project: AVL Tree Implementation
 * File: HashMap.h
 * Author: Melanie Lamp
 * Last Modified: 5/10/2020
 * Description: This class creates a key-pair using generic data types for keys 
 *			   and stores value inside a LinkedList. 
 */
#ifndef _HASHMAP_
#define _HASHMAP_
#include <array>
#include <iostream>
#include <list>
#include <stdbool.h>
#include <stdexcept>
#include <vector>
#include "Tree.h"

template<typename K, typename V>

/*
  * Class: HashMap
  * Description: Contains the methods for generating a key-pair using 
  * 			 generic data types for keys and stores value inside a LinkedList. 
  */
class HashMap
{
private:
	int capacity;
	int size;
	Tree<K, V> **arr;
	Tree<K, V> *newNode;
public:
	HashMap()
	{
		Tree<K, V> **arr;
		Tree<K, V> *newNode;
		int* list = new LinkedList(**arr);
		int capacity = 10;
		int size = 0;

		arr = new Tree<K, V>*[capacity];
		for (int i = 0; i < capacity; i++)
			arr[i] = NULL;
		newNode = new Tree<K, V>(-1, -1);
	}
/*
 * Function: containsValue
 * Description: Checks if the given value exists in the given BST.
 * Input:
 *     list - a pointer to the BST struct object to be deleted
 *     value - the value to search for
 * Output:
 *     bool - true if the tree contains the value, false if not
 */
	bool containsValue(int* list, V value)
	{
		int temp;
		list->value = root;
		if (root > value)
		{
			temp = current->left;
			return true;
		}
		else
		{
			temp = current->right;
			return true;
		}
		return false;
	}
/*
 * Function: put
 * Description: Adds the given value to the given BST if the value
 *              does not already exist in the tree.
 * Input:
 *     key - a pointer to the BST struct object
 *     value - the value to add
 */
	void put(K key, V value)
	{
		int hashKey = getHash(key);
		Tree* newNode = new Tree[key];
		int* list = new LinkedList(value);
		
		if (Tree[hashKey] == NULL)
			Tree[hashKey] = newNode;
		else
		{
			Tree* root = new Tree[hashKey];
			insert(newNode, key);
		}
	}
/*
 * Function: containsKey
 * Description: Checks if the given key exists in the given BST.
 * Input:
 *     key - a generic data type that retrieves the key
 * Output:
 *     bool - true if the tree contains the key, false if not.
 */
	bool containsKey(K key)
	{
		int hashKey = getHash(key);
		if (hashKey == key)
			return true;
		return false;
	}
/*
 * Function: getKeys
 * Description: Retrieves keys and contains them in a vector.
 * Output:
 *     Returns vector of integers as an array
 */
	std::vector getKeys()
	{
		vector<int> *vec = getHash(K key);
		**arr = new Array[vec];
		return arr;
	}
/*
 * Function: getHash
 * Description: Checks if the given key exists in the hashCode.
 * Input:
 *     key - a generic data type that retrieves the key
 * Output:
 *     Returns hash key code.
 */
	int getHash(K key)
	{
		if (key == NULL)
			return 0;
		else
		{
			int hash = key.hashCode();
			hash = hash >>> 16;
			hash = hash % capacity;
			return hash;
		}
	}
/*
 * Function: remove
 * Description: Removes a key with the given hash code.
 * Input:
 *     key - a generic data type that retrieves the key
 * Output:
 *     Returns NULL after removal.
 */
	V remove(K key)
	{
		int hashIndex = hashCode(key);
		*arr = new Array[hashIndex];

		if (arr[hashIndex]->key == NULL)
		{
			throw std::invalid_argument();
		}
		else
		{
			if (arr[hashIndex]->key == key)
			{
				Tree<K, V> *temp = arr[hashIndex];
				arr[hashIndex] = newNode;
				size--;
				return temp->value;
			}
			hashIndex++;
			hashIndex %= capacity;
		}
		return NULL;
	}
/*
 * Function: get
 * Description: Retrieves keys else throw invalid argument.
 * Output:
 *     Retrieves key or returns NULL.
 */
	V get(K key)
	{
		if (key == NULL)
		{
			throw std::invalid_argument();
		}
		else
		{
			Array *arr = new Array[hashIndex];
			int hashIndex = hashCode(key);
			int capacity = arr.size();
			int counter = 0;

			while (arr[hashIndex] != NULL)
			{
				counter++;
				if (counter > capacity)
					return NULL;
				if (arr[hashIndex]->key == key)
					return arr[hashIndex]->value;
				hashIndex++;
				hashIndex %= capacity;
			}
		}
		return NULL;
	}
/*
 * Function: hashCode
 * Description: Checks if the given key exists in the hashCode.
 * Input:
 *     key - a generic data type that retrieves the key
 * Output:
 *     Returns hash code.
 */
	int hashCode(K key)
	{
		int cap = HashMap->capacity;
		return key % cap;
	}
/*
 * Function: isEmpty
 * Description: Checks if the key is empty.
 * Output:
 *     bool - true if the tree contains the key, false if not.
 */
	bool isEmpty()
	{
		if (HashMap->key == NULL)
			return true;
		return false;
	}
/*
 * Function: clear
 * Description: Clears the hash map.
 */
	void clear()
	{
		HashMap.clear();
	}
};
#endif