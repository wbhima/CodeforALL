// 11 // Count words in a given string.
#include<iostream>
using namespace std;
int main()
{
    string str;
    str =  "one two three\n four\nfive";
    // cout << "\nEnter a string :  ";
    // getline(cin, str);
    
    int flag = 0, count = 0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            flag = 0;
        }
        else if(flag == 0)
        {
            flag = 1;
            count++;
        }
    }
    cout << endl << count << "\n\n";
}