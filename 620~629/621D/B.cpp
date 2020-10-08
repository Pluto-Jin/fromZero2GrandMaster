#include "bits/stdc++.h"
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while (t--) {
		int n,x;
		cin>>n>>x;
		vector<int> ar;
		set<int> s;
		ar.resize(n);
		for (auto &i:ar) {
			cin>>i;
			s.insert(i);
		}
		sort(ar.begin(),ar.end());
		int m=ar[n-1];
		int tmp=x%m;
		if (!tmp) cout<<x/m<<endl;
		else if (s.count(x)) cout<<1<<endl;
		else if (m>x) cout<<2<<endl;
		else cout<<x/m+1<<endl;


	}
}

