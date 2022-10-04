#include <iostream>

using namespace std;

int getSETBITS_of_one(int x){
    int counter_1=0;

    while(x!=0){
     if(x&1){
        counter_1++;
     }
     x=x>>1;
    }
    return counter_1;
}

int getSETBITS_of_zero(int y){
    int counter_0=0;

    while(y!=0){
     if(y&1){
     }
     else{
        counter_0++;
     }
     y=y>>1;
    }
    return counter_0;
}



int main(){
    int a,b;
    cout<<"ENTER THE 2 NUMBERS"<<endl;
    cin>>a>>b;
   /* int no_of_ones_of_a=getSETBITS_of_one(a);
    int no_of_zeros_of_a=getSETBITS_of_zero(a);
    int no_of_ones_of_b=getSETBITS_of_one(b);
    int no_of_zeros_of_b=getSETBITS_of_zero(b);*/

    cout<<"TOTAL NUMBER OF 1 BITS: "<<getSETBITS_of_one(a)+getSETBITS_of_one(b)<<endl;
    cout<<"TOTAL NUMBER OF 0 BITS: "<<getSETBITS_of_zero(a)+getSETBITS_of_zero(b)<<endl;

    return 0;
}