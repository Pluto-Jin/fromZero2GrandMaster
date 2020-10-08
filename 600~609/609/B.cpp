#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n,m;
	vector<int> a;
	vector<int>	b;
	cin>>n>>m;
	a.resize(n);
	b.resize(n);
	for (auto &i:a) cin>>i;
	for (auto &i:b) cin>>i;

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	int ans=numeric_limits<int>::max();
	for (int i=0;i<n;i++) 
	{
		int tmp=(b[i]-a[0]+m)%m;
		for (int j=0;j<n;j++)
		{
			if ((b[(i+j)%n]-a[j]+m)%m!=tmp) break;
			if (j==n-1) ans=min(ans,tmp);
		}
	}
	cout<<ans<<endl;
}
