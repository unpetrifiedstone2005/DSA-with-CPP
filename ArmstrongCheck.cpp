#include <bits/stdc++.h>


bool arm(int num){
    int og = num;
    int n = (int) log10(num)+1;
    int sum = 0;
    while(num){
        sum += pow((num%10),n);
        num /= 10;
    }
    
    return sum == og;
}

int main() {
    std::cout << (arm(153)?"true":"false");
}