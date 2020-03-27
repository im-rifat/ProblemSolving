#include <cstdio>
#include <cmath>
#include<cstring>
#include<cctype>
#include <iostream>

#define LIMIT 1001

using namespace std;

void generatePrime();
void factorization();
int numOfFactors(int);
void merge(int, int, int, int*);
void mergeSort(int, int, int*);
void sort();

int flag[LIMIT];
int factors[LIMIT];
int num[LIMIT];

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	generatePrime();
	factorization();
	sort();

	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		int a;
		scanf("%d", &a);
		printf("Case %d: %d\n", i, num[a]);
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
	for(int i = 0; i < LIMIT; i++) {
		num[i] = i;
	}

	mergeSort(1, LIMIT - 1, num);
}

void merge(int l, int mid, int r, int* num) {
	int i, j, k;
	int n1 = mid - l + 1;
	int n2 = r - mid;
	int LEFT[n1], RIGHT[n2];
	for(i = 0; i < n1; i++) LEFT[i] = num[l + i];
	for(j = 0; j < n2; j++) RIGHT[j] = num[mid + j + 1];

	i = j = 0;
	k = l;
	while(i < n1 && j < n2) {
		if(factors[LEFT[i]] < factors[RIGHT[j]]) {
			num[k] = LEFT[i];
			i++;
		} else if(factors[LEFT[i]] == factors[RIGHT[j]]) {
			if(LEFT[i] > RIGHT[j]) {
				num[k] = LEFT[i];
				i++;
			} else {
				num[k] = RIGHT[j];
				j++;
			}
		} else {
			num[k] = RIGHT[j++];
		}
		k++;
	}

	while(i < n1) {
		num[k++] = LEFT[i++];
	}
	
	while(j < n2) {
		num[k++] = RIGHT[j++];
	}
}

void mergeSort(int l, int r, int* num) {
	if(l < r) {
		int mid = l + (r - l) / 2;
		mergeSort(l, mid, num);
		mergeSort(mid+1, r, num);
		merge(l, mid, r, num);
	}
}