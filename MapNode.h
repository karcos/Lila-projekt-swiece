#pragma once
#include <iostream>
#include "List.h"

using namespace std;

class MapNode
{
private:
	string key_el;
	List* values_el;
	MapNode* next_el;
public:
	MapNode();
	// ~MapNode();

	void add(const string value);
	string key() const;
	void set_key(const string key);
	MapNode* next() const;
	void set_next(MapNode* new_next);
	List* values() const;
	int size() const;
	void show() const;
};

