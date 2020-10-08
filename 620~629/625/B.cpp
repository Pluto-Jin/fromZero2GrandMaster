#include "bits/stdc++.h"
using namespace std;

const long long N=5e5;
typedef long long ll;
ll cnt1[N],cnt2[N];
int main()
{
	int n;
	cin>>n;
	vector<ll> ar,br;
	ar.resize(n);
	br.resize(n);
	ll ans=0;
	for (auto &i:ar) cin>>i;
	for (int i=0;i<n;i++) {
		br[i]=ar[i]-i;
		if (br[i]>=0) {cnt1[br[i]]+=ar[i];
		ans=max(ans,cnt1[br[i]]);}
		else {cnt2[-br[i]]+=ar[i];
		ans=max(ans,cnt2[-br[i]]);}
	}
	cout<<ans<<endl;
}
