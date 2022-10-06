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
struct dsu
{
    int rank,parent,size;
};
vector<dsu> in(100010);
void make_set(int n)
{
    for(int i=1;i<=n;i++)
   {
       in[i].parent=i;
       in[i].size=1;
       in[i].rank=0;
   }
}
int find(int n)
{
    if(n==in[n].parent)
    return n;
    return in[n].parent=find(in[n].parent);
}
int unio(int a,int b)
{
    int p1,p2;
    p1=find(a);
    p2=find(b);
    if(p1==p2)
    return 0;
    if(in[p1].rank<in[p2].rank)
    {
        in[p2].size+=in[p1].size;
        in[p1].size=in[p2].size;
        in[p1].parent=p2;
    }
    else if(in[p1].rank>in[p2].rank)
    {
        in[p1].size+=in[p2].size;
        in[p2].size=in[p1].size;
        in[p2].parent=p1;
    }
    else
    {
        in[p1].size+=in[p2].size;
        in[p2].size=in[p1].size;
         in[p2].parent=p1;
         in[p1].rank++;
    }
    return 1;
}
void solve(int t)
{
   int n,m;
   cin>>n>>m;
   make_set(n);
   int c=n,ma=1;
   ru(i,m)
   {
       int a,b;
       cin>>a>>b;
       c=c-unio(a,b);
       ma=max(ma,in[in[a].parent].size);
      cout<<c<<" "<<ma<<"\n";
   }
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