#define _CRT_SECURE_NO_WARNINGS
#include "Worker.h"



Worker::Worker(const char* n, const int a) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	age = a;
}

char* Worker::getName() const {
	return name;
}

Worker::~Worker() { delete[] name; }
