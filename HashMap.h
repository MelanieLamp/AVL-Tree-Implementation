/*
* Project: CS133_ExtraCredit - HashMap AVL Tree Implementation
* File: HashMap.h
* Author: Melanie Lamp
* Date: 12/8/19
* Description: Class HashMap creates a key-pair using generic data types for keys 
*			   and stores value inside a LinkedList. It preforms rotations on inserted 
*			   nodes to rebalance height of AVL tree.
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

	bool containsKey(K key)
	{
		int hashKey = getHash(key);
		if (hashKey == key)
			return true;
		return false;
	}

	std::vector getKeys()
	{
		vector<int> *vec = getHash(K key);
		**arr = new Array[vec];
		return arr;
	}

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

	int hashCode(K key)
	{
		int cap = HashMap->capacity;
		return key % cap;
	}

	bool isEmpty()
	{
		if (HashMap->key == NULL)
			return true;
		return false;
	}

	void clear()
	{
		HashMap.clear();
	}
};
#endif