#include <bits/stdc++.h>
using namespace std;

bool palCheck(string str,int start, int end){
    if(start >= end || str[start] != str[end]){
        return 1;
    }else{
        return(str,++start,--end);
    }
    
    return 0;
}

int main() {
    string str = "racecar";
    cout<<(palCheck(str, 0, sizeof(str)/sizeof(str[0])-1)?"true":"false");
}