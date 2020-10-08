#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> ar;
	ar.resize(n);
	for (auto &i:ar) i.resize(m);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) {
			cin>>ar[i][j];
			if (ar[i][j]%m!=(j+1)%m) ar[i][j]=-1;
			else {ar[i][j]/=m;if (j==m-1) ar[i][j]--; if (ar[i][j]>=n) ar[i][j]=-1;}
		}

	int ans=0;
	for (int j=0;j<m;j++) {
		int tmp=n;
		vector<int> sft;
		sft.resize(n);
		for (int i=0;i<n;i++) {
			if (ar[i][j]==-1) continue;
			if (i>=ar[i][j]) sft[i-ar[i][j]]++;
			else sft[i+n-ar[i][j]]++;
		}
		for (int i=0;i<n;i++) {
			tmp=min(tmp,i+n-sft[i]);
		}
		ans+=tmp;
	}
	cout<<ans<<endl;

}

