//swap program without a third variable
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the two numbers\n";
    cout<<"First number:";
    cin>>a;
    cout<<"Second number:";
    cin>>b;
    a=a+b;
    b=a-b;
    a=a-b;
    cout<<"First number:"<<a<<"\nSecond number:"<<b;

}