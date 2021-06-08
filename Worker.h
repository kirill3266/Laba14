#ifndef Worker_h
#define Worker_h
#include <iostream>

class Worker {
protected:
	char* name;
	int age;
public:
	Worker(const char* n, const int a);
	char* getName() const;
	virtual int getSalary() const = 0;
	virtual std::ostream& print(std::ostream& out) const = 0;
	virtual ~Worker();
};

#endif // !Worker

