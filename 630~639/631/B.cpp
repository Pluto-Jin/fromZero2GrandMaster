#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while(t--) {
		int n,ok=1,m=0; cin>>n;
		vi ar(n),cnt(n);
		vector<ll> psum(n);
		for(int i=0;i<n;i++) {
			int x; cin>>x;
			ar[i]=x;
			psum[i]=x;
			psum[i]+=(i==0?0:psum[i-1]);
			cnt[x]++;
		}
		ll m1=0,m2=0,p=1;
		while (p<n and cnt[p]==2) p++;
		m1=p-1;
		while (p<n and cnt[p]==1) p++;
		m2=p-1;
		ll s1=(1ll+m1)*m1/2,s2=(1ll+m2)*m2/2;
		if (psum[n-1]!=s1+s2) {
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		vii ansp;
		if (psum[m1-1]==s1) {
			ans++;
			ansp.pb(mp(m1,m2));
		}
		if (m1!=m2 and psum[m2-1]==s2) {
			ans++;
			ansp.pb(mp(m2,m1));
		}
		cout<<ans<<endl;
		for (auto i:ansp) cout<<i.fi<<' '<<i.se<<endl;

	}
}

