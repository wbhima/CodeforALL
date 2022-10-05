#include<iostream>

using namespace std;



int main()
{
	long long x,y;

	cin>>x>>y;

	long long sum=x+y;
	long long diff=x-y;
	long long mul=x*y;

	cout<<x<<" "<<"+ "<<y<<" = "<<sum<<"\n";
	cout<<x<<" "<<"* "<<y<<" = "<<mul<<"\n";
	cout<<x<<" "<<"- "<<y<<" = "<<diff<<"\n";

}
