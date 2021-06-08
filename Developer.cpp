#include "Developer.h"

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
