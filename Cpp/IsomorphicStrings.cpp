//Program that checks two strings s and t, and determines if they are isomorphic.
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> m, m2;// stores charaters from both the strings in maps
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (m.find(s[i]) == m.end())
        {
            if (m2.find(t[i]) != m.end())
            {
                return false;
            }
            m2[t[i]] = s[i];
            m[s[i]] = t[i];
        }
        else
        {
            if (m[s[i]] != t[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<isIsomorphic(s,t);
    return 0;
}