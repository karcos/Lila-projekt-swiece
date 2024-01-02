#include "Map.h"

// Konstruktor
Map::Map()
{
	this->head = new MapNode;
	this->map_size = 0;
}

// Destruktor
//Map::~Map()
//{
//	MapNode* current = this->head;
//	while (current->next != nullptr)
//	{
//		MapNode* next_node = current->next;
//		delete current;
//		current = next_node;
//	}
//}

MapNode* Map::begin() const
{
	return this->head;
}

void Map::add_to_key(const string key, const string value)
{
	MapNode* current = this->head;
	while (current->next() != nullptr)
	{
		if (current->key() == key)
		{
			current->add(value);
			break;
		}
		current = current->next();
	}
}

void Map::add_element(const string key)
{
	MapNode* current = this->head;
	while (current->next() != nullptr) {
		current = current->next();
	}

	current->set_key(key);
	current->set_next(new MapNode);

	this->map_size++;
}

void Map::add_elements(const List keys)
{
	ListNode* current = keys.begin();

	while (current->next() != nullptr)
	{
		this->add_element(current->value());
		current = current->next();
	}
}

void Map::add_row(List values)
{	
	ListNode* current_list_el = values.begin();
	MapNode* current_map_el = this->head;

	while (current_list_el->next() != nullptr)
	{
		current_map_el->add(current_list_el->value());

		current_list_el = current_list_el->next();
		current_map_el = current_map_el->next();
	}
	
}

void Map::copy(const Map new_map)
{
	this->head = new_map.begin();
	this->map_size = new_map.size();
}

List* Map::get_row(const int row) const
{
	List* result_row = new List;
	MapNode* current_map_node = this->head;
	ListNode* current_list_node;
	/*int i;

	while (current_map_node->next() != nullptr)
	{
		current_list_node = current_map_node->values().begin();
		i = 0;

		while (i != row)
		{
			current_list_node = current_list_node->next();
			i++;
		}
		
		result_row.add(current_list_node->value());

		current_map_node = current_map_node->next();
	}*/

	for (int i = 0; i < this->map_size; i++)
	{
		if (row < this->head[i].values()->size() - 1)
		{
			result_row->add(this->head[i].values()->get(row));
		}
	}
	if (result_row->size() == 0)
	{
		result_row->add("null");
	}
	return result_row;
	
}

List* Map::get_by_key(const string key) const
{
	MapNode* current = this->begin();

	while (current->next() != nullptr)
	{
		if (current->key() == key)
		{
			return current->values();
		}
	}
}

void Map::show()
{
	MapNode* current = this->head;
	while (current->next() != nullptr)
	{
		current->show();
		if (current->next()->next() != nullptr)
		{
			cout << endl;
		}
		current = current->next();
	}
}

int Map::size() const
{
	return this->map_size;
}