#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<long long> ar;
	ar.resize(n);
	for (auto &i:ar) cin>>i;
	if (n>m) cout<<0<<endl;
	else {
		long long ans=1;
		for (int i=0;i<n-1;i++) {
			for (int j=i+1;j<n;j++) {
				ans*=abs(ar[i]-ar[j]);
				ans=ans%m;
			}
		}
		cout<<ans<<endl;
	}
}
