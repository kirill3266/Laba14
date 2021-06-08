#include "WorkerDB.h"

int WorkerDB::calcTotalSalary() {
	Node* p = workers->getFirst();
	int res = 0;
	for (int i = 0; i < size; i++) {
		res += p->val->getSalary();
		p = p->next;
	}
	return res;
}

WorkerDB::WorkerDB() {
	workers = new list;
	size = 0;
}

void WorkerDB::addWorker(Worker* w) {
	workers->push_back(w);
	size++;
}

void WorkerDB::eraseWorker(Worker* w) {
	workers->remove(w);
	size--;
}

void WorkerDB::findWorker(const char* _val) {
	Node* p = workers->find(_val);
	p->val->print(std::cout);
}

WorkerDB::~WorkerDB() {
	delete workers;
}