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

const int MOD=998244353;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	vi ar(n),br(m);
	map<int,int> last;
	int ok=(m<=n),mi=1e9+1;
	for (int i=0;i<n;i++) cin>>ar[i],mi=min(mi,ar[i]),last[ar[i]]=i;   
	for (int i=0;i<m;i++) {
		cin>>br[i];
		if (!last.count(br[i])) ok=0;
		if (ok and i and last[br[i]]<last[br[i-1]]) ok=0;
	}
	for (int i=last[br.back()];i<n;i++) if (ar[i]<br.back()) ok=0;
	if (!ok or br[0]!=mi) cout<<0<<endl;
	else {
		int ans=1;
		for (int i=1;i<m;i++) {
			int bg=last[br[i-1]],ed=last[br[i]],p1=bg,p2=ed;
			while (p1<ed and ar[p1]>=br[i-1]) p1++;
			if (p1!=ed) {ok=0;break;}
			while (p2>bg and ar[p2]>=br[i]) p2--;
			ans=1ll*ans*(ed-p2)%MOD;
		}
		cout<<(ok?ans:0)<<endl;
	}	


}

