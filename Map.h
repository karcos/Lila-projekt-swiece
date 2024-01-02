#pragma once

#include <iostream>
#include "MapNode.h"

using namespace std;
class Map {
private:
    MapNode *head;
    int map_size;

public:
    Map();
    // ~Map();
    void add_element(const string key);
    void add_elements(const List keys);
    void add_row(const List values);
    void add_to_key(const string key, const string value);
    MapNode* begin() const;
    void copy(const Map new_map);
    List* get_row(const int row) const;
    List* get_by_key(const string key) const;
    
    
    void show();
    int size() const;
};