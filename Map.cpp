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

int Map::size()
{
	return this->map_size;
}