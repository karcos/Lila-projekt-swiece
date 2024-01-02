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

void List::copy(const List new_list)
{
	this->head = new_list.begin();
	this->tail = new_list.end();
	this->list_size = new_list.size();
}

ListNode* List::begin() const
{
	return this->head;
}

ListNode* List::end() const
{
	return this->tail;
}

string List::get(int index) const
{
	return this->head[index].value();
}

void List::lower_values()
{
	ListNode* current = this->head;
	string tmp;
	while (current->next() != nullptr)
	{
		tmp = current->value();
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] >= 65 and tmp[i] <= 90)
			{
				tmp[i] -= 32;
			}
		}
		current->set_value(tmp);

		current = current->next();
	}
}

double List::get_max(int range_start, int range_end) const
{
	double maxi = atof(this->get(range_start).c_str()), tmp;

	for (int i = range_start + 1; i < range_end; i++)
	{
		tmp = atof(this->get(i).c_str());
		if (tmp > maxi)
		{
			maxi = tmp;
		}
	}

	return maxi;
}

double List::get_min(int range_start, int range_end) const
{
	double mini = atof(this->get(range_start).c_str()), tmp;

	for (int i = range_start + 1; i < range_end; i++)
	{
		tmp = atof(this->get(i).c_str());
		if (tmp < mini)
		{
			mini = tmp;
		}
	}

	return mini;
}

List* List::sublist(int range_start, int range_end) const
{
	List* result = new List;

	for (int i = range_start; i < range_end; i++)
	{
		result->add(this->get(i));
	}

	return result;
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
