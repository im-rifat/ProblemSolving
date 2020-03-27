/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool isPalindrom(char* str) {
    int len = strlen(str);
    
    bool palin = true;
    int count = 0;
    
    for(int i = 0, j = len-1; i <= j && palin; i++, j--) {
        if(str[i] == str[j]) continue;
        
        count++;
        
        if(count < 2) continue;
        
        palin = false;
    }
    
    if(count == 0 && len % 2 == 0) palin = false;
    
    return palin;
}

int main()
{
    
    char str[20];
    
    scanf("%s", str);
    
    printf("%s\n", isPalindrom(str) ? "YES" : "NO");

    return 0;
}
