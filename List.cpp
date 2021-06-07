#include "Laba14.h"

Node::Node(Worker* _val) {//+
	val = _val;
	next = nullptr;
}

list::list() {
	first = nullptr;
	last = nullptr;
}

bool list::is_empty() const {
	return first == nullptr;
}

void list::push_back(Worker* _val) {
	Node* p = new Node(_val);
	if (is_empty()) {
		first = p;
		last = p;
		return;
	}
	last->next = p;
	last = p;
}

void list::print() const {
	if (is_empty()) return;
	Node* p = first;
	while (p) { // p != nullptr
		std::cout << p->val << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

Node* list::find(const char* _val) {
	Node* p = first;
	while (p && std::strcmp(p->val->getName(), _val) != 0) p = p->next;
	return (p && std::strcmp(p->val->getName(), _val) == 0) ? p : nullptr;
}

void list::remove_first() {
	if (is_empty()) return;
	Node* p = first;
	first = p->next;
	delete p;
}

void list::remove_last() {
	if (is_empty()) return;
	if (first == last) {
		remove_first();
		return;
	}
	Node* p = first;
	while (p->next != last) p = p->next;
	p->next = nullptr;
	delete last;
	last = p;
}

void list::remove(Worker* _val) {
	if (is_empty()) return;
	if (std::strcmp(first->val->getName(), _val->getName()) == 0) {
		remove_first();
		return;
	}
	else if (std::strcmp(last->val->getName(), _val->getName()) == 0) {
		remove_last();
		return;
	}
	Node* slow = first;
	Node* fast = first->next;
	while (fast && std::strcmp(fast->val->getName(), _val->getName()) != 0) {
		fast = fast->next;
		slow = slow->next;
	}
	if (!fast) {
		std::cout << "This element does not exist" << std::endl;
		return;
	}
	slow->next = fast->next;
	delete fast;
}