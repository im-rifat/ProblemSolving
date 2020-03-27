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
#define LEN 200500

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

int numOfProblemSolved(const int n, const int k) {
	int index = 1;
	int time = k;

	for(index = 1; index <=n; index++) {
		if(time + (index * 5) > HOURS4) return index - 1;
		else time += (index * 5);
	}

	return n;
}

int numOfSteps(int n, int m) {
	queue<Point> Q;
	Q.push(Point(n, 0));
	bool flag[LEN];
	memset(flag, false, sizeof(flag));

	while(!Q.empty()) {
		Point a = Q.front();
		Q.pop();

		int x = a.x;
		int s = a.y;

		flag[x] = true;

		if(x == m) return s;

		int x1 = x*2;
		if(x1 == m) return s+1;
		else if(x1 <= LEN && !flag[x1]) Q.push(Point(x1, s+1));

		int x2 = x - 1;
		if(x2 == m) return s+1;
		else if(x2 > 0 && !flag[x2]) Q.push(Point(x2, s+1));
	}

	return -1;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", numOfSteps(n, k));
}
