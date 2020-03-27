#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    long long num;
    
    cin >> num;
    
    int count = 0;
    
    for(; num != 0; num /= 10) {
        int n = num % 10;
        if(n == 4 || n == 7) {
            count++;
        }
    }
    
    printf("%s\n", (count == 4 || count == 7) ? "YES" : "NO");

    return 0;
}
