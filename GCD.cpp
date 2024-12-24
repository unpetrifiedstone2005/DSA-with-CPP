#include<iostream>
using namespace std;


long int GCD(long int a, long int b){
   while(a>0 && b>0){
       if(a>b) a=a%b;
       else b = b%a;
   }
   
   if(a==0) return b;
   else return a;
}



int main(){
    int a,b;
    cout<<"Enter 1st number: ";
    cin >> a;
    cout<<"Enter 2nd number: ";
    cin >> b;
    cout << "The greatest common factor is " << GCD(a,b);

}