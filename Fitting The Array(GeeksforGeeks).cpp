//{ Driver Code Starts
/* Driver program to test above function */
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution{
public:
    
    bool isFit(int arr[], int brr[], int n){
        sort(arr,arr+n);
        sort(brr,brr+n);
        for(int i=0;i<n;i++){
            if(arr[i]>brr[i]) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int i,j,z,t,n,flag;
    cin>>t;
    for(z=0;z<t;z++)
    {
        flag=0;
        cin>>n;
        int arr[n+1], brr[n+1];
        
        for(i=0;i<n;i++)
            cin>>arr[i];
        for(i=0;i<n;i++)
            cin>>brr[i];
        
        Solution ob;
        
        if(ob.isFit(arr, brr, n))  cout<<"YES\n";
        else
            cout << "NO\n";
            
        
    }
    return 0;
}
// } Driver Code Ends
