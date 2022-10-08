#include<iostream>
using namespace std;

int main()
{
    string str1,str2;
    cout<<"Enter String 1: ";
    cin>>str1;
    cout<<"Enter String 2: ";
    cin>>str2;
    int H1[26]={0};
    int H2[26]={0};
    for (int i = 0; str1[i]!='\0'; i++)
    {
        H1[str1[i]-97]++;
    }
    for (int i = 0; str2[i]!='\0'; i++)
    {
        H2[str2[i]-97]++;
    }
    int flag=0;
    for (int i = 0; i < 26; i++)
    {
        if(H1[i]!=H2[i])
        {
            flag=1;
            cout<<"Strings are not anagram"<<endl;
            break;
        }
    }
    if(flag==0)
        cout<<"Strings are anagram"<<endl;
    
    return 0;
}
