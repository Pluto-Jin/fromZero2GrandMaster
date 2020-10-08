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

const ll INF=3e18+1;
int a,b,c;

ll solve(vi ar,vi br,vi cr) {
	ll res=INF;
	for (auto &i:ar) {
		int j,k,hi,lo;
		j=lower_bound(br.begin(),br.end(),i)-br.begin();
		k=lower_bound(cr.begin(),cr.end(),i)-cr.begin();
		if (j<br.size()) {
			hi=br[j];
			if (k<cr.size() and cr[k]==i) lo=cr[k];
			else if (k>0) lo=cr[k-1];
			else lo=0;
			if (lo) res=min(res,1ll*(hi-i)*(hi-i)+1ll*(i-lo)*(i-lo)+1ll*(hi-lo)*(hi-lo));
		}
	}
	return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>a>>b>>c;
		vi ar(a),br(b),cr(c);
		for (auto &i:ar) cin>>i;
		for (auto &i:br) cin>>i;
		for (auto &i:cr) cin>>i;
		sort(ar.begin(),ar.end());
		sort(br.begin(),br.end());
		sort(cr.begin(),cr.end());
		ll ans=INF;
		ans=min(ans,solve(ar,br,cr));
		ans=min(ans,solve(ar,cr,br));
		ans=min(ans,solve(br,ar,cr));
		ans=min(ans,solve(br,cr,ar));
		ans=min(ans,solve(cr,ar,br));
		ans=min(ans,solve(cr,br,ar));
		cout<<ans<<endl;
	}
}

