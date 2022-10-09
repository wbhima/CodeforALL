#include<iostream>
#include<cmath>
using namespace std;


void binaryToDecimal(){
    
    int binary,decimal=0;
    cout<<"enter binary number ";
    cin>>binary;
    int count,i=0;

    while(binary!=0){
        count=binary%10;
        decimal+=count*pow(2,i);
        i++;
        binary/=10;
    }
    cout<<decimal;

}

void octalToDecimal(){

    int binary,decimal=0;
    cout<<"enter octal number ";
    cin>>binary;
    int count,i=0;

    while(binary!=0){
        count=binary%10;
        decimal+=count*pow(8,i);
        i++;
        binary/=10;
    }
    cout<<decimal;

}

void hexadecimalToDecimal(){

    string binary;
    int decimal=0;
    cout<<"enter binary number ";
    cin>>binary;
    int count,i=0;

    for(i=0;i<=binary.size();i++){
        if(binary[i]>='0'&&binary[i]<='9'){
            decimal+=binary[i];

        }
    }  
}

void decimalToBinary(){

    int binary,decimal;
    cout<<"enter decimal number ";
    cin>>decimal;
    int count,i=0;
    
}
int main(){

    binaryToDecimal();
    octalToDecimal();
    hexadecimalToDecimal();
    decimalToBinary();

    return 0;
}
