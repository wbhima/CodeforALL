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
vector<pair<int,int>> adj[100010];
void solve(int t)
{
   int n,m;
   cin>>n>>m;
   ru(i,m)
   {
       int a,b,c;
       cin>>a>>b>>c;
       adj[a].pb({b,c});
       adj[b].pb({a,c});
   }
   vector<ll> mst(n+1,0),key(n+1,INT_MAX);
//    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
set<pair<ll,ll>> q;
    key[1]=0;
    //mst[1]=1;
    q.insert({0,1});
    ll ans=0;
   for(int i=1;i<=n-1;i++)
   {
       if(q.empty())
       {
           cout<<"IMPOSSIBLE";
           return;
       }
       auto x=q.begin();
       int w=x->first;
       int v=x->second;
       q.erase(q.begin());
       mst[v]=1;
       for(auto to:adj[v])
       {
           if(mst[to.first]==0&&key[to.first]>to.second)
           {
               q.erase({key[to.first],to.first});
               key[to.first]=to.second;
               q.insert({key[to.first],to.first});
           }
       }
   }
   for(int i=1;i<=n;i++)
   {
       ans+=key[i];
   }
   cout<<ans;
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