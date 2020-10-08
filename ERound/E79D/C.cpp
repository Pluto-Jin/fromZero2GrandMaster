#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int m,n;
		cin>>n>>m;
		vector<int> ar;
		vector<int> br;
		ar.resize(n);
		br.resize(m);
		for (auto &i:ar) cin>>i;
		for (auto &i:br) cin>>i;

		map<int,int> dic;
		for (int i=0;i<n;i++) dic[ar[i]]=i;
		long long ans=m;
		int pos=-1;
		for (int i=0;i<m;i++) {
			if (dic[br[i]]>pos) {
				ans+=2*(dic[br[i]]-i);
				pos=dic[br[i]];
			}
		}
		cout<<ans<<endl;
	}
}
