#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int n,m;
		cin>>n>>m;
		vector<int> ar;
		ar.resize(n);
		for (auto &i:ar) cin>>i;
		int s=0;
		for (int i=0;i<n;i++) {
			s+=ar[i];
		}
		cout<<min(s,m)<<endl;
	}
}
