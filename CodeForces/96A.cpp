/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char players[101];
    
    scanf("%s", players);
    
    //printf("%s\n", players);
    
    char current = '-', prev = '+';
    int count = 0;
    for(int i = 0; players[i] != '\0' && count < 7; i++) {
        if(i == 0) current = players[i], count = 1;
        else {
            prev = current;
            current = players[i];
            
            if(current == prev) count++;
            else count = 1;
        }
    }
    
    printf("%s\n", count >= 7 ? "YES" : "NO");

    return 0;
}
