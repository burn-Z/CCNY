#ifndef HM3_MATRIXPROCS_H
#define HM3_MATRIXPROCS_H

#include <iostream>
#include <vector>

using namespace std;

const int N = 4;

void print(int a[][N]);

bool areEqual(int a[][N],int b[][N]);

bool isIdentity(int a[][N]);

bool isEven(int ij);
void evenAndOdd(int a[][N], int& numOfEvens, int& numOfOdds);

vector<int> sumOfColumns(int a[][N]);

int* sumOfRows(int a[][N]);

void sortByRowAndColumn(int (*a)[N]);

#endif