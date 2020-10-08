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

const int N=1e5+1;
vi edge[N];
int par[N],dep[N];

void dfs(int &ans,int at,int d=0,int p=-1) {
	dep[at]=d;
	par[at]=p;
	int cnt=0;
	for (auto to:edge[at]) {
		if (to==par[at]) continue;
		if (edge[to].size()==1) cnt++;
		dfs(ans,to,d+1,at);
	}
	if (cnt) ans-=cnt-(dep[at]!=1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y);
		edge[y].pb(x);
	}
	int ok=1,ans=n-1;
	for (int i=1;i<=n;i++) {
		if (edge[i].size()==1) {
			dfs(ans,i);
			break;
		}
	}
	for (int i=1;i<=n;i++) {
		if (edge[i].size()==1 and dep[i]%2) {
			ok=0;
			break;
		}
	}
	cout<<(ok?1:3)<<' '<<ans<<endl;
}

