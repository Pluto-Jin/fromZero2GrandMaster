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
int n,k,par[N],dep[N];
ll ans;
vi edge[N],res;

int dfs(int at,int d=0,int p=-1) {
	int sz=0;
	dep[at]=d;
	par[at]=p;
	for (auto to:edge[at]) {
		if (to==par[at]) continue;
		sz+=dfs(to,d+1,at);
	}
	res.pb(sz-dep[at]);
	return sz+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>k;
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y);
		edge[y].pb(x);
	}
	dfs(1);
	sort(res.begin(),res.end());
	for (int i=n-1;i>=k;i--) ans+=res[i];
	cout<<ans<<endl;
}

