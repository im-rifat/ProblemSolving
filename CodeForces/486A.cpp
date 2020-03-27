/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    
    long long int n;
    scanf("%lld", &n);
    
    long long int even = n >> 1;
    long long int odd = n - even;
    
    printf("%lld\n", (even*even) + even - (odd*odd));

    return 0;
}
