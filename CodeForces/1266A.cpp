#include<cstdio>
#include<cstring>
#include<sstream>
#include <string>


#define SIZE 111

using namespace std;

bool divisibleByThree(char *num) {
	int sum = 0;

	while(*num != '\0') {
		sum += (*num - '0');
		num++;
	}

	return sum % 3 == 0;
}

int numOfZero(char *num) {
	int sum = 0;

	while(*num != '\0') {
		if(*num == '0') sum++;
		num++;
	}

	return sum;
}

int numOfEven(char *num) {
	int sum = 0;

	while(*num != '\0') {
		if((*num - '0') % 2 == 0 && *num != '0') sum++;
		num++;
	}

	return sum;
}

int main() {

	char num[SIZE];
	int n;
	scanf("%d", &n);

	while(n--) {
		scanf("%s", num);

		int zero = numOfZero(num);
		int even = numOfEven(num);

		bool three = divisibleByThree(num);
		bool six = false;
		if(three && zero > 0) {
			if(even > 0 || (zero-1) > 0 || zero == strlen(num)) six = true;
		}

		printf("%s\n", six ? "red" : "cyan");
	}
	return 0;
}