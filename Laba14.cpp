#define _CRT_SECURE_NO_WARNINGS
#include "Laba14.h"
#include <string.h>
#include <iostream>
#include <cstring>

Worker::Worker(const char* n, const int a) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	age = a;
}

char* Worker::getName() const {
	return name;
}

Worker::~Worker() { delete[] name; }

Developer::Developer(const char* name, const int age, const int b, const int exp, const float l, const bool isB, const int bon) : Worker(name, age) {
	base = b;
	expirience = exp;
	level = (l <= 2 && l >= 1) ? l : 1;
	isBonus = isB;
	bonus = bon;
}

int Developer::getSalary() const {
	int res = isBonus ? base + level * 1000 + bonus : base + level * 1000;
	return res;
}

std::ostream& Developer::print(std::ostream& out) const {
	return out << "Developer" << " " << name << " " << age << " " << base << " " << expirience << " " << level << " " << isBonus << " " << bonus << "\n";
}

Sale::Sale(const char* name, const int age, const char* b, const int p, const int nu, const float per) : Worker(name, age) {
	branch = new char[strlen(b) + 1];
	strcpy(branch, b);
	price = p;
	num = nu;
	percent = per;
}

int Sale::getSalary() const {
	int res = price * num * percent;
	return res;
}


std::ostream& Sale::print(std::ostream& out) const {
	return out << "Sale" << " " << name << " " << age << " " << branch << " " << price << " " << num << " " << percent << "\n";;
}
/*std::ostream& operator<<(std::ostream& out,const Sale& sale) {
	return out << "Sale" << " " << sale.name << " " << sale.age << " " << sale.branch << " " << sale.price << " " << sale.num << " " << sale.percent << "\n";
}*/

Sale:: ~Sale() { delete[] branch; }

Accountant::Accountant(const char* name, const int age, const int b, const bool isB, const int bon) : Worker(name, age) {
	base = b;
	isBonus = isB;
	bonus = bon;
}

int Accountant::getSalary() const {
	int res = isBonus ? base + bonus : base;
	return res;
}

std::ostream& Accountant::print(std::ostream& out) const {
	return out << "Accountant" << " " << name << " " << age << " " << base << " " << isBonus << " " << bonus << "\n";
}

/*std::ostream& operator<<(std::ostream& out,const Accountant& acc) {
	return out << "Accountant" << " " << acc.name<< " " << acc.age << " " << acc.base << " " << acc.isBonus << " " << acc.bonus << "\n";
}*/

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

Node* list::getFirst() const {
	return first;
}

Node* list::getLast() const {
	return last;
}

int WorkerDB::calcTotalSalary() {
	Node* p = workers->getFirst();
	int res = 0;
	for (int i = 0; i < size; i++) {
		res += p->val->getSalary();
		p = p->next;
	}
	return res;
}

WorkerDB::~WorkerDB() {
	delete workers;
}