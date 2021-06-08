#include "Accountant.h"

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