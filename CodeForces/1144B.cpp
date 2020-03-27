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
#define LEN 2003

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

long long int minimumSum(vector<int> &a, vector<int> &b, int aLen, int bLen) {
	//for(int i = 0; i <= bLen; i++) a.pop_back();
	int len = aLen - bLen - 1;

	long long int sum = 0;
	for(int i = 0; i < len; i++) sum += a[i];

	return sum;
}

int main() {
	int n, arr[LEN];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	sort(arr, arr + n);

	vector<int> odd, even;
	for(int i = 0; i < n; i++) {
		if(arr[i] % 2 == 0) {
			even.push_back(arr[i]);
		} else odd.push_back(arr[i]);
	}

	int oddLen = odd.size();
	int evenLen = even.size();

	long long int sum = 0;

	if(oddLen != 0 && evenLen != 0) {
		if(oddLen == evenLen) printf("%lld\n", sum);
		else {
			if(oddLen > evenLen) printf("%lld\n", minimumSum(odd, even, oddLen, evenLen));
			else printf("%lld\n", minimumSum(even, odd, evenLen, oddLen));
		}
	} else {
		if(oddLen == 0) {
			for(int i = 0; i < evenLen - 1; i++) sum += even[i];
		} else for(int i = 0; i < oddLen - 1; i++) sum += odd[i];

		printf("%lld\n", sum);
	}
}
