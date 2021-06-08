#define _CRT_SECURE_NO_WARNINGS
#include "Sale.h"
#include <cstring>

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

Sale:: ~Sale() { delete[] branch; }