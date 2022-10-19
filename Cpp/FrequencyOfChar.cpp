#include <bits/stdc++.h>
using namespace std;
 
void printFrequency(string str)
{
    // Define an unordered_map
    unordered_map<char, int> M;
 
    // Traverse string str check if
    // current character is present
    // or not
    for (int i = 0; str[i]; i++)
    {
        // If the current characters
        // is not found then insert
        // current characters with
        // frequency 1
        if (M.find(str[i]) == M.end())
        {
            M.insert(make_pair(str[i], 1));
        }
 
        // Else update the frequency
        else
        {
            M[str[i]]++;
        }
    }
 
    // Traverse the map to print the
    // frequency
    for (auto& it : M) {
        cout << it.first << ' ' << it.second << '\n';
    }
}
 
// Driver Code
int main()
{
    string str = "geeksforgeeks";
 
    // Function call
    printFrequency(str);
    return 0;
}
