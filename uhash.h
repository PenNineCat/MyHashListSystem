#pragma once

#include <string>
#include "node.h"

class uhash {
public:
	node* root_node_array = nullptr;
	int array_num = 0;
	int array_max = 0;

	uhash();
	uhash(std::string key, int add_num = 1);
	void new_key(std::string key, int add_num = 1);
	int hash_key(std::string key);
	void decrease_key(std::string key, int decrease_num = 1);
	void delete_key(std::string key);
	void print_table();
};