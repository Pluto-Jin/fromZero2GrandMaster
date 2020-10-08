#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		ll n,m; cin>>n>>m;
		vii ar(m+1); 
		for (int i=1;i<=m;i++) {
			int x,y; cin>>x>>y;
			ar[i]=mp(x,y);
		}
		sort(ar.begin(),ar.end());

		vector<ll> sum(m+1);
		for (int i=1;i<=m;i++) sum[i]=sum[i-1]+ar[i].fi;
		ll ans=sum[m]-sum[m-min(n,m)];
		for (int i=1;i<=m;i++) {
			int x=ar[i].se,lo=0,hi=m+1;
			while (lo<hi-1) {
				int mid=(lo+hi)/2;
				if (ar[mid].fi<x) lo=mid;
				else hi=mid;
			}
			int cnt=m-lo;
			if (cnt>n) continue;
			ll cur=sum[m]-sum[lo];
			if (lo<i) cur+=x*(n-cnt);
			else cur+=ar[i].fi+x*(n-cnt-1);
			ans=max(ans,cur);
		}
		cout<<ans<<endl;
	} 
}

