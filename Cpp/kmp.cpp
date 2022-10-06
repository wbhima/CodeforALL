#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ru(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define sv(v) sort(v.begin(),v.end())
#define ff first
#define ss second
#define debug2(a,b) cout<<a<<" "<<b<<"\n";
ll mod = 1e9+7;
ll mod2 = 998244353;
 
ll po(ll x, ll y, ll p)
{
    ll res = 1; x = x % p;   
    while (y > 0) { if (y & 1) res = (res * x) % p; y >>= 1; x = (x * x) % p; } 
    return res%p; 
}
ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll highestPowerof2(ll n)
{
   ll p = (ll)log2(n);
   return (ll)pow(2, p);
}
void solve(int t)
{
   string st,p;
   cin>>st>>p;
   string s=p+"!"+st;
   int n=s.size();
   vector<int> kmp(n);
   int ans=0;
   for(int i=1;i<n;i++)
   {
       int j=kmp[i-1];
       while(j!=0 && s[i]!=s[j])
       j=kmp[j-1];
       if(s[i]==s[j])
       j++;
       kmp[i]=j;
       if(j==p.size())
       ans++;
   }
   cout<<ans<<"\n";
}
signed main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    freopen("err.txt","w",stderr);
    #endif
    // auto start = chrono::high_resolution_clock::now();
	int t=1;
	// cin>>t;
	for(int i=1;i<=t;i++)
    {
        solve(i);
    }
    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    // cout << duration.count() << " ms\n";
	return 0;
}