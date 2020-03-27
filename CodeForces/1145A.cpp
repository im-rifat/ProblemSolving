/*
 * DCP_546.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: rifat
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include<cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define LIMIT 111
#define LEN 20

using namespace std;

struct Point {
	int x, y;

	Point(int a, int b) {
		x = a;
		y = b;
	}
};

const char orient[]="ONLS";
const int dx[]={0, -1, 0, 1, -1, -1, 1, 1};
const int dy[]={-1, 0, 1, 0, 1, -1, 1, -1};

bool inGrid(Point &p, int row, int col) {
	return p.x >= 0 && p.x < row && p.y >= 0 && p.y < col;
}

const int HOURS4 = 240;

int l = 1;

bool isSorted(int i, int j, int* arr) {
	bool sorted = true;

	for(int a = i+1; a <= j && sorted; a++) {
		if(arr[a] < arr[a - 1]) sorted = false;
	}

	return sorted;
}

int lenOfArray(int i, int j) {
	if(i > j) return (i - j) + 1;
	else return (j - i) + 1;
}

void thanosSort(int* arr, int n, int i, int j) {
	if(l == n) return;

	if(i < j) {
		bool sorted = isSorted(i, j, arr);
		if(sorted) {
			int len = lenOfArray(i, j);
			if(len > l) l = len;
		}

		int mid = i + ((j - i) / 2);
		//printf("len %d\tmid %d\ti %d\tj %d\n", l, mid, i, j);

		thanosSort(arr, n, i, mid);
		thanosSort(arr, n, mid+1, j);
	}
}

int main() {
	int n, arr[LEN];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	thanosSort(arr, n, 0, n - 1);

	printf("%d\n", l);
}
