#ifndef Sale_h
#define Sale_h
#include"Worker.h"

class Sale : public Worker {
protected:
	char* branch;//branch name
	int price;//elemen price
	int num;//num of elements sold
	float percent;//sale's percent
public:
	Sale(const char* name, const int age, const char* b, const int p, const int nu, const float per);
	virtual int getSalary() const;
	virtual std::ostream& print(std::ostream& out) const;
	~Sale();
};

#endif // ! Sale

