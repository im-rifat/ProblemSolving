#include <cstdio>
#include <cmath>
#include<cstring>
#include<cctype>
#include <iostream>

#define LIMIT 101

using namespace std;

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	char in[LIMIT][11], temp[11];
	int n;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", in[i]);
	}
	
	strcpy(temp, in[0]);
	
	int count1 = 0; // this for team A
	int indexB = -1; // position of team B
	
	for(int i = 0; i < n; i++) {
		if(strcmp(temp, in[i]) == 0) count1++;
		else indexB = i;
	}
	
	int count2 = n - count1;
	if(count1 > count2) printf("%s\n", temp);
	else printf("%s\n", in[indexB]);
	
	return 0;
}