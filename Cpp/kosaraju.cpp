#include<bits/stdc++.h>
#define ll long long int
ll mod = (int)1e9+7;
#define mod2 998244353
#define pb push_back
#define ru(i,n) for(int i=0;i<n;i++)
#define run(x,v) for(auto x:v)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define vii vector<vector<int>>
#define mp make_pair
#define pb push_back
#define inp(a,n) ru(i,n){cin>>a[i];}
#define sv(v) sort(v.begin(),v.end())
#define sa(a) sort(a,a+size(a)/size(a[0]))
using namespace std;
#define m1 -1e16
#define m2 1e16
#define ff first
#define ss second
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
vector<int> adj[100010],adj2[100010];
vector<int> visited(100010),comp(100010);
void dfs(int s,stack<int> &st)
{   
    visited[s]=1;
    for(auto x:adj[s])
    {
        if(!visited[x])
        dfs(x,st);
    }
    st.push(s);
}
void dfs2(int s,int king)
{
    visited[s]=1;
    comp[s]=king;
    for(auto x:adj2[s])
    {
        if(!visited[x])
        dfs2(x,king);
    }
}
void solve(int t)
{
   int n,m;
   cin>>n>>m;
   ru(i,m)
   {
       int x,y;
       cin>>x>>y;
       adj[x].pb(y);
       adj2[y].pb(x);
   }
   stack<int> st;
   for(int i=1;i<=n;i++)
   {
       if(!visited[i])
       {
           dfs(i,st);
       }
   }
   for(int i=1;i<=n;i++)
   {
       visited[i]=0;
   }
   int king=1;
   while(!st.empty())
   {
       int to=st.top();
       st.pop();
       if(visited[to])
       continue;
       dfs2(to,king);
       king++;
   }
   cout<<king-1<<"\n";
   for(int i=1;i<=n;i++)
   cout<<comp[i]<<" ";
}
signed main()
{ 
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
	// cin>>t;
	rep(i,1,t+1)
    {
        solve(i);
    }
	return 0;
}