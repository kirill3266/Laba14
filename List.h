#ifndef List_h
#define List_h
#include "Worker.h"

struct Node {
	Worker* val;
	Node* next;
	Node(Worker* _val);
};

struct list {
protected:
	Node* first;
	Node* last;
public:
	list();
	bool is_empty() const;
	void push_back(Worker* _val);
	Node* getFirst() const;
	Node* getLast() const;
	void remove_first();
	void remove_last();
	void remove(Worker* _val);
	Node* find(const char* _val);
	void print() const;
};

#endif // ! List