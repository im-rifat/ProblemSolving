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
#define LEN 50050

using namespace std;

struct Point {
	int x, y;
};

const char orient[]="ONLS";
const int dx[]={0, -1, 0, 1, -1, -1, 1, 1};
const int dy[]={-1, 0, 1, 0, 1, -1, 1, -1};

bool inGrid(Point &p, int row, int col) {
	return p.x >= 0 && p.x < row && p.y >= 0 && p.y < col;
}

const int HOURS4 = 240;

int numOfProblemSolved(const int n, const int k) {
	int index = 1;
	int time = k;

	for(index = 1; index <=n; index++) {
		if(time + (index * 5) > HOURS4) return index - 1;
		else time += (index * 5);
	}

	return n;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", numOfProblemSolved(n, k));
}
