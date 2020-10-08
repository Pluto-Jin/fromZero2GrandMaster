#include "bits/stdc++.h"
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while (t--) {
		int n,d;
		cin>>n>>d;
		vector<int> ar;
		ar.resize(n);
		for (auto &i:ar) cin>>i;

		int ans=ar[0];
		for (int i=1;i<n;i++) {
			if (d<i) break;
			if (d>=ar[i]*i) {ans+=ar[i];d-=ar[i]*i;continue;}
			ans+=d/i;
			break;
		}
		cout<<ans<<endl;
	}
}

