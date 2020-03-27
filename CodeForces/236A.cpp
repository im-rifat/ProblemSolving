/*
 * DCP_546.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: rifat
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

#define LIMIT 50

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

void init(int* k) {
	for(int i = 0; i < LIMIT; i++) {
		k[i] = 0;
	}
}

int biSearch(int l, int r, int* k, int* sv) {
	int mid = r + l;
	int pos = mid;

	while(l <= r) {
		mid = l + (r - l) / 2;
		pos = mid;

		printf("%d %d\n", k[mid], mid);

		if(k[mid] > *sv) {
			r = mid-1;
		} else if(k[mid] == *sv) break;
		else l = mid+1;
	}

	return pos;
}

int main() {
	char username[101];

	bool letters[26];

	int count = 0;

	scanf("%s", username);

	for(int i = 0; i < 26; i++) letters[i] = false;

	for(int i = 0; username[i] != '\0'; i++) {
		if(letters[username[i] - 'a'] == false) {
			letters[username[i] - 'a'] = true;
			count++;
		}
	}

	if(count % 2 == 0) {
		printf("CHAT WITH HER!\n");
	} else printf("IGNORE HIM!\n");

	return 0;
}
