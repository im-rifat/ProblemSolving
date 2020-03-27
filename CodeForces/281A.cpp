#include <cstdio>
#include <cmath>
#include<cstring>
#include<cctype>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

#define LIMIT 1001

const int MASK=97;

using namespace std;

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	char a[LIMIT];
	scanf("%s", a);
	printf("%c%s\n", toupper(a[0]), a+1);

	return 0;
}