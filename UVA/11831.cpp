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

#define LIMIT 111
#define LEN 50050

using namespace std;

struct Point {
	int x, y;
};

const char orient[]="ONLS";
const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};

bool inGrid(Point &p, int row, int col) {
	return p.x >= 0 && p.x < row && p.y >= 0 && p.y < col;
}

char grid[LIMIT][LIMIT];
char cmd[LEN];
Point robotPos;
int currOri;

int main() {
	int n, m, s;
	while(scanf("%d %d %d", &n, &m, &s) == 3 && (n != 0 || m != 0 || s != 0)) {
		bool found = false;
		getchar();

		for(int i = 0; i < n; i++) {
			scanf("%s", grid[i]);

			for(int j = 0; j < m && !found; j++) {
				for(int k = 0; k < 4; k++) {
					if(orient[k] == grid[i][j]) {
						robotPos.x = i;
						robotPos.y = j;
						grid[i][j] = '.';
						currOri = k;
						found = true;
					}
				}
			}
		}

		int sticker = 0;
		scanf("%s", cmd);

		for(int i = 0; cmd[i] != '\0'; i++) {
			if(cmd[i] == 'D') {
				if(currOri == 3) {
					currOri = 0;
					continue;
				}
				currOri++;
			} else if(cmd[i] == 'E') {
				if(currOri == 0) {
					currOri = 3;
					continue;
				}
				currOri--;
			} else if(cmd[i] == 'F') {
				Point temp;
				temp.x = robotPos.x + dx[currOri];
				temp.y = robotPos.y + dy[currOri];
				if(inGrid(temp, n, m) == false) continue;
				if(grid[temp.x][temp.y] == '#') continue;
				if(grid[temp.x][temp.y] == '*') {
					sticker++;
					grid[temp.x][temp.y] = '.';
				}
				robotPos.x = temp.x, robotPos.y = temp.y;
			}
		}

		printf("%d\n", sticker);
	}
}
