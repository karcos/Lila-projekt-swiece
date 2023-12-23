#pragma once
#include "ListNode.h"
#include "MyChar.h"

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
	ListNode* begin() const;
	ListNode* end() const;
	void lower_values();
	void pop();
	int size() const;
	void show() const;
	
};

