#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector<int> ar,br,cr;
		ar.resize(n);
		br.resize(n);
		for (auto &i:ar) cin>>i;
		for (auto &i:br) cin>>i;
		sort(ar.begin(),ar.end());
		sort(br.begin(),br.end());
		for (auto i:ar) cout<<i<<" ";
		cout<<endl;
		for (auto i:br) cout<<i<<" ";
		cout<<endl;
	}
}
