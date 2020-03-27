/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    int sum = a, c;
    while(1) {
        c = a / b;
        a = c + (a % b);
        sum += c;
        
        if(a < b) break;
    }
    
    printf("%d\n", sum);

    return 0;
}
