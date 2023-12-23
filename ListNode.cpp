#include "ListNode.h"

ListNode::ListNode()
{
	this->value_el = "";
	this->next_el = nullptr;
	this->prev_el = nullptr;
}

ListNode* ListNode::next() const
{
	return this->next_el;
}

ListNode* ListNode::prev() const
{
	return this->prev_el;
}

void ListNode::set_next(ListNode* new_next)
{
	this->next_el = new_next;
}

void ListNode::set_prev(ListNode* new_prev)
{
	this->prev_el = new_prev;
}

string ListNode::value() const
{
	return this->value_el;
}

void ListNode::set_value(const string new_value)
{
	this->value_el = new_value;
}

//ListNode::~ListNode()
//{
//	free(this->next_el);
//	free(this->prev_el);
//}