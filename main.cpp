#include "Worker.h"
#include "WorkerDB.h"
#include "Sale.h"
#include "Accountant.h"
#include "Developer.h"
#include "List.h"


int main() {
	WorkerDB db;
	Developer d1("Masha", 20, 2000, 10, 1.1, false, 500);
	Developer d2("Kolya", 21, 2000, 5, 1.7, true, 1000);
	Sale s("Marina", 25, " Spb ", 500, 20, 5);
	Accountant a("Evgeniy", 35, 3000, true, 5);
	db.addWorker(&d1);
	db.addWorker(&d2);
	db.addWorker(&s);
	db.addWorker(&a);
	int total = db.calcTotalSalary();
	std::cout << "Total is: " << total << "\n";
	db.eraseWorker(&s);
	total = db.calcTotalSalary();
	std::cout << "Total is: " << total << "\n";
	db.findWorker("Evgeniy");
	db.findWorker("Masha");
	return 0;
}