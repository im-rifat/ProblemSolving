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
    long long int n, k, w, j;
    
    scanf("%lld %lld %lld", &k, &n, &w);
    
    j = (((w * (w +1)) / 2) * k) - n;
    
    if(j < 0) j = 0;
    
    printf("%lld\n", j);

    return 0;
}
