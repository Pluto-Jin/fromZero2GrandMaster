#include "bits/stdc++.h"
using namespace std;

int t;
long long r,g,b,m;
long long sum;

int main()
{
	cin>>t;
	while (t--)
	{
		cin>>r>>g>>b;
		sum=r+g+b;
		m=max(r,max(g,b));
		if (sum-m<m-1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}
