#include<cstdio>
#include<cstring>
#include<sstream>
#include <string>

using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	if(a+b == c+d) printf("YES\n");
	else if(a + c == b + d) printf("YES\n");
	else if(a + d == b + c) printf("YES\n");
	else if(a + b + c == d) printf("YES\n");
	else if(a + c + d == b) printf("YES\n");
	else if(b + c + d == a) printf("YES\n");
	else if(a + b + d == c) printf("YES\n");
	else printf("NO\n");
	return 0;
}
