/*
 * DCP_546.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: rifat
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <cmath>
#include<vector>
#include<queue>
#include<algorithm>

#define LIMIT 11

using namespace std;

struct Point {
	int x, y;

	Point() {
		this->x = -1;
		this->y = -1;
	}

	Point(int a, int b) {
		this->x = a;
		this->y = b;
	}

	bool operator == (const Point &p) const {
		return this->x == p.x && this->y == p.y;
	}

	bool operator != (const Point &p) const {
		return this->x != p.x || this->y != p.y;
	}
};

const int GRID_DIR_4[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char grid[LIMIT][LIMIT];
int N;
Point foods[26];

bool withinGrid(Point &p) {
	if(p.x >= 0 && p.y >= 0 && p.x < N && p.y < N) return true;
	return false;
}

bool validCell(Point &p) {
	if(grid[p.x][p.y] == '#') return false;
	return true;
}

int bfs(Point &src, Point &dst) {
	int cost[N][N];
	memset(cost, 0, sizeof(cost));

	queue<Point> Q;
	cost[src.x][src.y] = 0;
	Q.push(src);

	while(!Q.empty()) {
		Point a = Q.front();
		Q.pop();

		for(int i = 0; i < 4; i++) {
			Point b = Point(a.x + GRID_DIR_4[i][0], a.y + GRID_DIR_4[i][1]);
			if(!withinGrid(b) || !validCell(b) || cost[b.x][b.y] != 0) continue;

			cost[b.x][b.y] = cost[a.x][a.y] + 1;

			if(grid[b.x][b.y] != '.' && grid[b.x][b.y] > grid[dst.x][dst.y]) continue;
			if(b == dst) return cost[b.x][b.y];

			Q.push(b);
		}
	}

	return 0;
}

int main() {
	int T;

	scanf("%d", &T);

	for(int testCase = 1; testCase <= T; testCase++) {
		scanf("%d\n", &N);

		for(int i = 0; i < N; i++) {
			//gets(grid[i]);
			scanf("%s", grid[i]);
		}

		int k = 0;

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
					foods[grid[i][j] - 'A'] = Point(i, j);
					//printf("%d, %d\n", i, j);
					k++;
				} else continue;
			}
		}

		int cost = 0;
		bool flag = false;

		for(int i = 0; i < k - 1 && !flag; i++) {
			int val = bfs(foods[i], foods[i+1]);
			//printf("%d\n", val);
			if(val == 0) flag = true;
			cost += val;
		}

		if(flag) {
			printf("Case %d: Impossible\n", testCase);
		} else {
			printf("Case %d: %d\n", testCase, cost);
		}
	}

	return 0;
}
