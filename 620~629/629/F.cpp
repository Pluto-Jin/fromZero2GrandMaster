#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
//#define endl '\n'
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

	int n,k; cin>>n>>k;
	vi ar(n);
	vii br;
	for (auto &i:ar) cin>>i;
	sort(ar.begin(),ar.end());
	for (int i=0;i<n;i++) {
		int x=ar[i];
		if (br.empty() or br.back().fi!=x) br.pb(mp(x,1));
		else br.back().se++;
		if (br.back().se==k) {
			cout<<0<<endl;
			return 0;
		}
	}
	int tmp=br.size();
	vector<ll> ft(tmp),pre(tmp),bk(tmp),suf(tmp);
	for (int i=1;i<tmp;i++) {
		ll tg=br[i].fi,val=br[i-1].fi;
		ft[i]=ft[i-1]+br[i-1].se;
		pre[i]=pre[i-1]+ft[i]*(tg-val);
	}
	for (int i=tmp-2;i>=0;i--) {
		ll tg=br[i].fi,val=br[i+1].fi;
		bk[i]=bk[i+1]+br[i+1].se;
		suf[i]=suf[i+1]+bk[i]*(val-tg);
	}
	ll ans=1e15;
	for (int i=0;i<tmp;i++) {
		ll num=br[i].se;
		if (ft[i]+num>=k) ans=min(ans,pre[i]-(ft[i]+num-1ll*k));
		if (bk[i]+num>=k) ans=min(ans,suf[i]-(bk[i]+num-1ll*k));
		ans=min(ans,pre[i]+suf[i]-(n-k));
	}
	cout<<ans<<endl;

}

