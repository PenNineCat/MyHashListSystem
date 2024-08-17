#include "uhash.h"
#include <iostream>

#define MAX_STORAGE_INHENCE_NUM 30

using namespace std;


uhash::uhash()
{
	root_node_array = new node[MAX_STORAGE_INHENCE_NUM];
	array_max = MAX_STORAGE_INHENCE_NUM;
}

uhash::uhash(string key, int add_num)
{
	root_node_array = new node[MAX_STORAGE_INHENCE_NUM];
	array_max = MAX_STORAGE_INHENCE_NUM;
	new_key(key, add_num);
}

int uhash::hash_key(string key)
{
	const char* char_ptr = key.c_str();
	int hash_key = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash_key += (int)char_ptr[i];
	}
	if (hash_key < 0)
	{
		hash_key = 0 - hash_key;
	}
	if (hash_key >= array_max)
	{
		if (char_ptr[0] > 0)
		{
			hash_key = (hash_key % 2) + (hash_key % 3) + (hash_key % 4) + (hash_key % 5) + (hash_key / (int)char_ptr[0]);
		}
		else
		{
			hash_key = (hash_key % 2) + (hash_key % 3) + (hash_key % 4) + (hash_key % 5) - (hash_key / (int)char_ptr[0]);
		}
	}
	while (1)
	{
		if (hash_key >= array_max)
		{
			node* new_space = new node[array_max + MAX_STORAGE_INHENCE_NUM];
			for (int i = 0; i < array_max; i++)
			{
				new_space[i] = root_node_array[i];
			}

			delete[] root_node_array;
			root_node_array = new_space;
			new_space = nullptr;
			array_max += MAX_STORAGE_INHENCE_NUM;
		}
		else
		{
			break;
		}
	}


	return hash_key;
}

void uhash::new_key(string key, int add_num)
{
	if (root_node_array[hash_key(key)].key == "null")
	{
		root_node_array[hash_key(key)].key = key;
		root_node_array[hash_key(key)].val = add_num;
	}
	else if (root_node_array[hash_key(key)].key == key)
	{
		root_node_array[hash_key(key)].val += add_num;
	}
	else
	{
		root_node_array[hash_key(key)].end_insert_node(key, add_num);
	}
}

void uhash::decrease_key(string key, int decrease_num)
{
	if (root_node_array[hash_key(key)].key == key && root_node_array[hash_key(key)].val >= decrease_num)
	{
		root_node_array[hash_key(key)].val -= decrease_num;
	}
	else if (root_node_array[hash_key(key)].key == key && root_node_array[hash_key(key)].val < decrease_num)
	{
		delete_key(key);
	}
	else if (root_node_array[hash_key(key)].key != key)
	{
		root_node_array[hash_key(key)].position_decreace_node(key, decrease_num);
	}
}

void uhash::delete_key(string key)
{
	if (root_node_array[hash_key(key)].key == key)
	{
		root_node_array[hash_key(key)].head_delete_node();
	}
	else
	{
		root_node_array[hash_key(key)].position_delete_node(key);
	}
}

void uhash::print_table()
{
	for (int i = 0; i < array_max; i++)
	{
		cout << "½Úµã" << i << endl;
		root_node_array[i].print_node();
		cout << endl;
	}
}