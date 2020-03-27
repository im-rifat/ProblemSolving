#include <cstdio>
#include <cmath>
#include<cstring>
#include<cctype>
#include <iostream>
#include <algorithm>
#include <vector>

#define LIMIT 507

using namespace std;

bool isValidMove(int, int, int, int);
void insertionSort(int*, int);
void dfs(int, int, int, int, int*);

struct Point {
	int x;
	int y;
	
	Point(int a, int b) {
		x = a;
		y = b;
	}
};

int num[LIMIT];
char grid[LIMIT][LIMIT];
int flag[LIMIT][LIMIT];
vector<Point> locs;

char WALL = '#';
char CRYSTAL = 'C';
char VISITED = 'V';

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	int col, row, q, t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		scanf("%d %d %d", &row, &col, &q);
		getchar();
		for(int j = 0; j < row; j++) {
			scanf("%s", grid[j]);
		}
		
		for(int j = 0; j < row; j++) {
			for(int k = 0; k < col; k++) {
				if(grid[j][k] != WALL && grid[j][k] != VISITED) {
					int count = 0;
					dfs(j, k, row, col, &count);
					int len = locs.size();
					for(int l = 0; l < len; l++) {
						flag[locs[l].x][locs[l].y] = count;
					}
					locs.clear();
				}
			}
		}
		
		printf("Case %d:\n", i);
		for(int j = 0; j < q; j++) {
			int x, y;
		
			scanf("%d %d", &x, &y);
			printf("%d\n", flag[x - 1][y - 1]);
		}
	}

	return 0;
}

void dfs(int x, int y, int row, int col, int* count) {
	if(isValidMove(x, y, row, col) == false) return;
	if(grid[x][y] == WALL || grid[x][y] == VISITED) return;
	
	if(grid[x][y] == CRYSTAL) *count += 1;
	grid[x][y] = VISITED;
	locs.push_back(Point(x, y));
	
	dfs(x+1, y, row, col, count);
	dfs(x-1, y, row, col, count);
	dfs(x, y+1, row, col, count);
	dfs(x, y-1, row, col, count);
}

bool isValidMove(int x, int y, int row, int col) {
	if(x >=0 && x < row && y >=0 && y < col) return true;
	return false;
}