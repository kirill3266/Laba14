#ifndef Laba14
#define Laba14
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

class WorkerDB {
private:
	list* workers;
	size_t size;
public:
	WorkerDB();
	void addWorker(Worker* w);
	void eraseWorker(Worker* w);
	void findWorker(const char* _val);
	int calcTotalSalary();
	~WorkerDB();
};

#endif // !Laba14
