#include<bits/stdc++.h>
using namespace std;
vector<long long int>s,a;
void create_segment(int l,int r,int pos)
{
	int mid=l+(r-l)/2;
	if(l==r)
	{
		s[pos]=a[l];
		return;
	}
	create_segment(l,mid,2*pos+1);
	create_segment(mid+1,r,2*pos+2);
	s[pos]=(s[2*pos+1]+s[2*pos+2]);
}
long long int ans_query(int ql,int qr,int l,int r,int pos)
{
	if(ql<=l&&qr>=r)
	return s[pos];
	if(ql>r||qr<l)
	return 0;
	
	int mid=l+(r-l)/2;
	
	return (ans_query(ql,qr,l,mid,2*pos+1)+ans_query(ql,qr,mid+1,r,2*pos+2));
}
void update(int l,int r,int pos,long long int u,int k)
{
	if(k<l||k>r)
	return;
	int mid=l+(r-l)/2;
	s[pos]+=u;
	if(l!=r)
	{
		update(l,mid,2*pos+1,u,k);
		update(mid+1,r,2*pos+2,u,k);
	}
}
int main()
{
    int n,q;
    cin>>n>>q;
	s.assign(4*n,INT_MAX);
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
    create_segment(0,n-1,0);
    while(q--)
    {
		long long int x,y,z;
		cin>>z>>x>>y;
		if(z==2)
		cout<<ans_query(x-1,y-1,0,n-1,0)<<"\n";
		else
		{
			long long int u=y-a[x-1];
			a[x-1]=y;
			update(0,n-1,0,u,x-1);
		}
	}
    
    return  0;
}