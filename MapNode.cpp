#include "MapNode.h"

MapNode::MapNode()
{
	this->key_el = "";
	this->next_el = nullptr;
}

//MapNode::~MapNode()
//{
//	cout << "MapNode: " << this->key << endl;
//}

string MapNode::key() const
{
	return this->key_el;
}

void MapNode::set_key(const string key)
{
	this->key_el = key;
}

int MapNode::size() const
{
	return this->values_el->size();
}

void MapNode::show() const
{
	cout << '{' << this->key_el << " ,";
	this->values_el->show();
	cout << '}';
}

void MapNode::add(const string value)
{
	this->values_el->add(value);
}

MapNode* MapNode::next() const
{
	return this->next_el;
}

void MapNode::set_next(MapNode* new_next)
{
	this->next_el = new_next;
}

List* MapNode::values() const
{
	return this->values_el;
}
