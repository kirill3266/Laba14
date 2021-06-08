#ifndef WorkerDB_h
#define WorkerDB_h
#include"list.h"

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

#endif // !WorkerDB

