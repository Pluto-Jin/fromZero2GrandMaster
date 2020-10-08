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
int br[N],vis[N],d[N],mk[N];
ll ar[N],dp[N];
vi fr,bc;

void dfs(int at) {vis[at]=1;d[br[at]]++;if (br[at] and !vis[br[at]]) dfs(br[at]);} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<=n;i++) cin>>ar[i];
	for (int i=1;i<=n;i++) { cin>>br[i]; if (br[i]==-1) br[i]=0; }
	
	for (int i=1;i<=n;i++) if (!vis[i]) dfs(i);
	queue<int> q;
	for (int i=1;i<=n;i++) if (!d[i]) q.push(i);
	ll ans=0;
	while (q.size()) {
		int tmp=q.front(); q.pop();
		if (!tmp) continue;
		ans+=ar[tmp];
		if (!--d[br[tmp]]) q.push(br[tmp]);
		if (ar[tmp]>=0) fr.pb(tmp),ar[br[tmp]]+=ar[tmp];
		else bc.pb(tmp);
	}
	cout<<ans<<endl;
	for (auto i:fr) cout<<i<<' ';
	reverse(bc.begin(),bc.end());
	for (auto i:bc) cout<<i<<' '; cout<<endl;
}

