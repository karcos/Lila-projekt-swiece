#pragma once
#include "ListNode.h"
#include <cstdlib>


class List
{
private:
	ListNode* head;
	ListNode* tail;
	int list_size;

public:
	List();
	// ~List();
	void add(const string value);
	void copy(const List new_list);
	ListNode* begin() const;
	ListNode* end() const;
	string get(int index) const;
	void lower_values();
	double get_max(int range_start, int range_end) const;
	double get_min(int range_start, int range_end) const;
	List* sublist(int range_start, int range_end) const;
	void pop();
	int size() const;
	void show() const;
	
};

