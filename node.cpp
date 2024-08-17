#include "node.h"
#include <iostream>

using namespace std;

node::node(string key, int val, node* base_node)
{
	this->key = key;
	this->val = val;
	this->next_node_ptr = base_node;
}

void node::head_insert_node(string key, int val)
{
	node* temp = new node(*this);
	this->val = val;
	this->key = key;
	this->next_node_ptr = temp;
}

void node::end_insert_node(string key, int val)
{
	node* serach_ptr = this;
	while (1)
	{
		if (serach_ptr->next_node_ptr == nullptr)
		{
			break;
		}
		serach_ptr = serach_ptr->next_node_ptr;
	}
	serach_ptr->next_node_ptr = new node(key, val);
}

void node::head_delete_node()
{
	node* temp = this;
	this->val = this->next_node_ptr->val;
	this->next_node_ptr = this->next_node_ptr->next_node_ptr;
	delete temp;
}

void node::end_delete_node()
{
	node* temp = this;
	while (1)
	{
		if (temp->next_node_ptr != nullptr)
		{
			temp = temp->next_node_ptr;
		}
		else
		{
			delete temp;
			return;
		}
	}
}

void node::position_insert_node(string key, string serach_key, int val)
{
	node* temp = this;
	while (1)
	{
		if (temp->key == serach_key)
		{
			node* new_node = new node(key, val, temp->next_node_ptr);
			temp->next_node_ptr = new_node;
			break;
		}
		else if(temp->next_node_ptr != nullptr)
		{
			temp = temp->next_node_ptr;
		}
		else
		{
			break;
		}
	}
}

void node::position_delete_node(string serach_key)
{
	node* temp = this;
	node* delete_node = nullptr;
	while (1)
	{
		if (temp->key == serach_key)
		{
			delete_node = temp->next_node_ptr;
			temp->next_node_ptr = temp->next_node_ptr->next_node_ptr;
			delete delete_node;
			break;
		}
		else if(temp->next_node_ptr != nullptr)
		{
			temp = temp->next_node_ptr;
		}
		else
		{
			break;
		}
	}
}

void node::position_decreace_node(string serach_key, int decreace_num)
{
	node* temp = this;
	while (1)
	{
		if (temp->key == serach_key)
		{
			if (temp->val >= decreace_num)
			{
				temp->val -= decreace_num;
			}
			else
			{
				position_delete_node(serach_key);
			}
			break;
		}
		else if(temp->next_node_ptr !=nullptr)
		{
			temp = temp->next_node_ptr;
		}
		else
		{
			break;
		}
	}
}

void node::position_increace_node(string serach_key, int add_num)
{
	node* temp = this;
	while (1)
	{
		if (temp->key == serach_key)
		{
			temp->val += add_num;
			break;
		}
		else if(temp->next_node_ptr != nullptr)
		{
			temp = temp->next_node_ptr;
		}
		else
		{
			break;
		}
	}
}

void node::print_node()
{
	node* temp = this;
	while (1)
	{
		cout << temp->key << " " << temp->val << endl;
		cout << " ¡ý  " << endl;
		if (temp->next_node_ptr == nullptr)
		{
			break;
		}
		temp = temp->next_node_ptr;
	}
}
