#include <cstdio>
#include <cmath>
#include<cstring>
#include<cctype>
#include <iostream>

#define LIMIT 111

using namespace std;

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	char in[LIMIT];
	char out[LIMIT * 2];
	
	scanf("%s", in);
	int len = strlen(in);
	
	int j = 0;
	for(int i = 0; in[i] != '\0'; i++) {
		char c = in[i];
		if(c >= 'A' && c <= 'Z') {
			c += 32;
		}
		
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') continue;
		out[j++] = '.';
		out[j++] = c;
	}
	out[j] = '\0';
	
	printf("%s\n", out);
	
	return 0;
}