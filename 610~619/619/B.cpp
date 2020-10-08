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
		ar.resize(n);
		for (auto &i:ar) cin>>i;

		int l=1e9+1,r=-1;
		int tmp=0;
		for (int i=0;i<ar.size();i++) {
			if (ar[i]==-1) {
				if (i>0 and ar[i-1]!=-1) {
					l=min(l,ar[i-1]);
					r=max(r,ar[i-1]);
				}
				if (i<ar.size()-1 and ar[i+1]!=-1) {
					l=min(l,ar[i+1]);
					r=max(r,ar[i+1]);
				}
			}
			else if (i<ar.size()-1 and ar[i+1]!=-1) {
				tmp=max(tmp,abs(ar[i]-ar[i+1]));
			}
		}
		if (l==1e9+1 and r==-1) l=r=0;
		int ans=(r-l)/2+l;
		tmp=max(tmp,abs(r-ans));
		cout<<tmp<<" "<<ans<<endl;
	}
}
