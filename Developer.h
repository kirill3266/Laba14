#ifndef Developer_h
#define Developer_h
#include"Worker.h"

class Developer : public Worker {
protected:
	int base;//fixed salary
	int expirience;
	float level;//qualification(float fro 1 to 2)
	bool isBonus;
	int bonus;
public:
	Developer(const char* name, const int age, const int b, const int exp, const float l, const bool isB, const int bon);
	virtual int getSalary() const;
	virtual std::ostream& print(std::ostream& out) const;
};

#endif // ! Developer

