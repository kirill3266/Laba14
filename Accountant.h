#ifndef Accountant_h
#define Accountant_h 
#include "Worker.h"

class Accountant :public Worker {
protected:
	int base; //fixed salary
	bool isBonus;
	int bonus;
public:
	Accountant(const char* name, const int age, const int b, const bool isB, const int bon);
	virtual int getSalary() const;
	virtual std::ostream& print(std::ostream& out) const;
};

#endif // !Accountant

