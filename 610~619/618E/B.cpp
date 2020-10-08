#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector<int> ar;
		ar.resize(2*n);
		for (auto &i:ar) cin>>i;

		sort(ar.begin(),ar.end());
		cout<<ar[n]-ar[n-1]<<endl;
	}
}
