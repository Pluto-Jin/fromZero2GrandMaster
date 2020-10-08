#include "bits/stdc++.h"
using namespace std;

int main()
{
	int q;
	cin>>q;
	while (q--) {
		int n,m;
		cin>>n>>m;
		vector<array<int,3>> ar;
		ar.resize(n);
		for (auto &i:ar) cin>>i[0]>>i[1]>>i[2];

		int curr=0,flag=0;
		int lo=m,hi=m;
		for (int i=0;i<n;i++) {
			int tmp=ar[i][0]-curr;
			curr=ar[i][0];
			lo-=tmp;
			hi+=tmp;
			if (hi<ar[i][1] or lo>ar[i][2]) {flag=1;break;}
			lo=max(lo,ar[i][1]);
			hi=min(hi,ar[i][2]);
		}
		if (flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}
