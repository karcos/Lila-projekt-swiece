#include "List.h"

List::List()
{
	this->head = new ListNode;
	this->tail = this->head;
	this->list_size = 0;
}

//List::~List()
//{
//	ListNode* current = this->head;
//	while (current != nullptr) {
//		ListNode* next_node = current->next();
//		delete current;
//		current = next_node;
//	}
//}

void List::add(const string value)
{
	this->tail->set_value(value);
	this->tail->set_next(new ListNode);
	this->tail->next()->set_prev(this->tail);

	this->tail = this->tail->next();

	this->list_size++;
}

ListNode* List::begin() const
{
	return this->head;
}

ListNode* List::end() const
{
	return this->tail;
}

void List::lower_values()
{
	ListNode* current = this->head;

	while (current->next() != nullptr)
	{
		current->set_value(lower(current->value()));
		current = current->next();
	}
}

void List::pop()
{
	this->tail = this->tail->prev();
	this->tail->set_next(nullptr);
	this->tail->set_value("");
	this->list_size--;
}

int List::size() const
{
	return this->list_size;
}

void List::show() const
{
	ListNode* current = this->head;
	cout << '{';
	while (current->next() != nullptr)
	{
		cout << current->value();
		if (current->next()->next() != nullptr)
		{
			cout << ", ";
		}
		current = current->next();
	}
	cout << '}';
}
