#pragma once
#include <iostream>

using namespace std;

class ListNode
{
private:
	string value_el;
	ListNode* next_el;
	ListNode* prev_el;
public:
	ListNode();
	// ~ListNode();
	ListNode* next() const;
	ListNode* prev() const;
	void set_next(ListNode* new_next);
	void set_prev(ListNode* new_prev);
	string value() const;
	void set_value(const string new_value);
};

