#include <cstdio>
#include <cmath>
#include<cstring>
#include <iostream>

using namespace std;

const int LIMIT = 201;

void generatePrime();
void factorization();
int numOfFactors(int);
void merge(int, int, int*);
void mergeSort(int, int, int*);
void sort();

short flag[LIMIT];
int factors[LIMIT];

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	int t;
	scanf("%d", &t);
	getchar();
	for(int i = 0; i < t; i++) {
		char str[107];
		scanf("%s", str);
		int len = strlen(str);
		if(len <= 10) {
			printf("%s\n", str);
		} else {
			int count = len - 2;
			printf("%c%d%c\n", str[0], count, str[len - 1]);
		}
	}

	return 0;
}

void generatePrime() {
	for(int i = 0; i < LIMIT; i++) {
		flag[i] = 1;
	}
	flag[0] = flag[1] = 0;
	for(int j = 4; j < LIMIT; j+=2) {
		flag[j] = 0;
	}

	int root = sqrt(LIMIT);
	for(int i = 3; i <= root; i+=2) {
		if(flag[i] == 1) {
			for(int j = i * i; j < LIMIT; j += (2 * i)) {
				flag[j] = 0;
			}
		}
	}

	for(int i = 2; i < LIMIT; i++) {
		if(flag[i] == 1) printf("%d\n", i);
	}
}

void factorization() {
	for(int i = 0; i < LIMIT; i++) {
		factors[i] = 0;
	}

	for(int i = 2; i < LIMIT; i++) {
		if(flag[i] == 1) {
			factors[i] = 2;
		} else {
			factors[i] = numOfFactors(i);
		}

		printf("%d = %d\n", i, factors[i]);
	}
}

int numOfFactors(int a) {
	int root = sqrt(a);
	int num = 1;
	int temp = a;
	for (int i = 2; i <= root; i++) {
		if(flag[i] == 1 && temp % i == 0) {
			int count = 0;
			while(temp % i == 0) {
				count += 1;
				temp /= i;
			}

			num *= (count + 1);
		}
	}

	if(temp != 1) {
		num *= 2;
	}

	return num;
}

void sort() {
}