#pragma once

#include <string>

class node {
private:

public:
	node* next_node_ptr = nullptr;
	std::string key = "null";
	int val = 0;
	node(std::string key = "null", int val = 0, node* base_node = nullptr);
	void head_insert_node(std::string key, int val = 0);
	void head_delete_node();
	void end_insert_node(std::string key, int val = 0);
	void end_delete_node();
	void position_insert_node(std::string key, std::string serach_key, int val = 0);
	void position_delete_node(std::string serach_key);
	void position_decreace_node(std::string serach_key, int decrease_num);
	void position_increace_node(std::string serach_key, int add_num);
	void print_node();
};