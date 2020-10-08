#include "bits/stdc++.h"
using namespace std;

const int N=1e5+5;
int r[N],b[N];

int main() 
{
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		fill(r,r+n+1,1e9);
		fill(b,b+n+1,1e9);
		b[0]=n;
		int cnt=0;
		for (int i=1;i<=n;i++) {
			int tmp;
			cin>>tmp;
			if (tmp==1) cnt++;
			else cnt--;
			if (cnt>0) r[cnt]=n-i;
			else b[-cnt]=n-i;
		}
		int ans=n+b[0];
		cnt=0;
		vector<int> ar;
		ar.resize(n);
		for (auto &i:ar) cin>>i;
		for (int i=n-1;i>=0;i--) {
			int tmp=ar[i];
			if (tmp==1) cnt++;
			else cnt--;
			if (cnt>=0) ans=min(ans,b[cnt]+i);
			else ans=min(ans,r[-cnt]+i);
		}
		cout<<ans<<endl;
	}
}

