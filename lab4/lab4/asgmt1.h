#ifndef ASGMT1_H
#define ASGMT1_H

#include <vector>

void runAsgmt1(void);

void sortAscOrderVector(const int& N);
void sortAscOrderCArray(const int& N);
void sortDescOrderVector(const int& N);
void sortDescOrderCArray(const int& N);

void printVector(const std::vector<int>& v);
void printCArray(int c[], int length);

bool greater(int x, int y);

#endif // !ASGMT1_H
