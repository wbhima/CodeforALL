#include <iostream>
using namespace std;

int main()
{
    char op;
    double num1, num2;
    cout<<"Enter operator(+,-,*,/) - "<<endl;
    cin>>op;
    cout<<"Enter two numbers- "<<endl;
    cin>>num1>>num2;
    
    switch(op)
    {
        case '+':
        {
            cout<<num1<<" + "<<num2<<" = "<<(num1+num2)<<endl;
            break;
        }
        case '-':
        {
            cout<<num1<<" - "<<num2<<" = "<<(num1-num2)<<endl;
            break;
        }
        
        case '*':
        {
            cout<<num1<<" * "<<num2<<" = "<<(num1*num2)<<endl;
            break;
        }
        
        case '/':
        {
            if(num2 ==0){
                cout<<"Invalid operation"<<endl;
            }
            else{
                cout<<num1<<"/"<<num2<<" = "<<(num1/num2)<<endl;
                break;
            }
            
        }
        default:
        {
            cout<<"Invalid operator"<<endl;
        }
        
    }
    return 0;

}