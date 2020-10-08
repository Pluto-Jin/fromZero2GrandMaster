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

const int N=2e5+1;
int pos[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	ll n,m,x,k,y; cin>>n>>m>>x>>k>>y;
	vi ar(n+1),br(m+1);
	for (int i=1;i<=n;i++) cin>>ar[i],pos[ar[i]]=i;
	int ok=1;
	for (int i=1;i<=m;i++) {
		cin>>br[i];
		if (pos[br[i]]<pos[br[i-1]]) ok=0;
	}
	br.pb(br.back());
	if (!ok) cout<<-1<<endl;
	else {
		int way=y*k>x;
		ll ans=0;
		for (int i=1;i<=m+1;i++) {
			int cnt,ma=0;
			if (i!=m+1) cnt=pos[br[i]]-pos[br[i-1]]-1;
			else cnt=n-pos[br[i-1]];
			for (int j=pos[br[i-1]]+1;j<(i==m+1?n+1:pos[br[i]]);j++) ma=max(ma,ar[j]);
			if (ma>max(br[i],br[i-1]) and cnt<k) {ok=0;break;}
			if (way) ans+=cnt/k*x+cnt%k*y;
			else if (ma>max(br[i],br[i-1])) ans+=x+(cnt-k)*y;
			else ans+=cnt*y;
		}
		if (!ok) cout<<-1<<endl;
		else cout<<ans<<endl;
	}

}

