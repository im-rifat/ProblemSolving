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

char grid[LIMIT][LIMIT];
char tempGrid[LIMIT][LIMIT];
char cmd[LIMIT];
Point robotPos;
int currOri;

int areaLake(int x, int y, int row, int col) {
	Point p;
	p.x = x, p.y = y;
	if(inGrid(p, row, col) == false) return 0;
	if(grid[x][y] == 'V' || grid[x][y] == 'L') return 0;
	grid[x][y] = 'V';

	int newx[8], newy[8];
	for(int i = 0; i < 8; i++) {
		newx[i] = x + dx[i];
		newy[i] = y + dy[i];
	}

	return 1 + areaLake(newx[0], newy[0], row, col) + areaLake(newx[1], newy[1], row, col)
			+ areaLake(newx[2], newy[2], row, col) + areaLake(newx[3], newy[3], row, col)
			+ areaLake(newx[4], newy[4], row, col) + areaLake(newx[5], newy[5], row, col)
			+ areaLake(newx[6], newy[6], row, col) + areaLake(newx[7], newy[7], row, col);
}

int main() {
	int t;
	bool flag = false;
	scanf("%d", &t);
	getchar();
	getchar();

	while(t--) {

		int row = 0, col = 0;
		int x = 0, y = 0;

		if(flag) printf("\n");
		flag = true;

		while(gets(cmd)) {
			if(strlen(cmd) == 0) break;
			if(cmd[0] >= 'A' && cmd[0] <= 'Z') {
				strcpy(tempGrid[row], cmd);
				strcpy(grid[row], cmd);
				row++;
				continue;
			}
			sscanf(cmd, "%d %d", &x, &y);
			x--, y--, col = strlen(grid[0]);

			if(grid[x][y] != 'W') {
				printf("0\n");
				continue;
			}

			printf("%d\n", areaLake(x, y, row, col));

			// rebuild
			for(int i = 0; i < row; i++) {
				strcpy(grid[i], tempGrid[i]);
			}
		}
	}
}
