#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string totalTime[1441];
bool palindrom[1441];
int count;

bool isPalindrom(string t) {
    for(int i = 0, j = 4; i <= j; i++, j--) {
        if(t[i] != t[j]) return false;
    }
    
    return true;
}

void preCalculation() {
    count = 0;
    for(int i = 0; i < 24; i++) {
        for(int j = 0; j < 60; j++) {
            totalTime[count] = ((i < 10) ? "0" : "") + to_string(i) + ":" + ((j < 10) ? "0" : "") + to_string(j);
            palindrom[count] = isPalindrom(totalTime[count]);
            
            //count++;
            
            //cout << totalTime[count] << endl;
            count++;
        }
    }
    
    //cout << count;
}

int main() {
    preCalculation();
    
    string t;
    
    cin >> t;
    
    int pos = 0;
    
    for(int i = 0; i <= count; i++) {
        //cout << totalTime[i] << endl;
        if(totalTime[i] == t) {
            pos = i;
            break;
        }
    }

   //cout << pos;
    
    for(int i = pos +1; ; i++) {
        //cout << palindrom[i % count];
        if(palindrom[i % count]) {
            printf("%s\n", totalTime[i % count].c_str());
            break;
        }
    }

    return 0;
}
