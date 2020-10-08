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

const int N=2e5+1;
bool vis[N],mark[N];
int dep[N],deg[N],par[N],n,m,tg;
vi edge[N],ans1,ans2;

bool solve1() {
	while (ans1.size()<tg) {
		int mi=1e9,at;
		for (int i=1;i<=n;i++) {
			if (vis[i]) continue;
			if (deg[i]<mi) mi=deg[i],at=i;	
		}
		if (mi>=tg-1) return false;
		ans1.pb(at);
		vis[at]=true;
		for (auto to:edge[at]) {
			vis[to]=true;
			for (auto tt:edge[to]) if (!vis[tt]) deg[tt]--;
		}
	}
	return true;
}
int solve2(int at) {
	mark[at]=true;
	ans2.pb(at);
	dep[at]=dep[par[at]]+1;
	for (auto to:edge[at]) {
		if (dep[at]<tg) break;
		if (vis[to] or !mark[to] or to==par[at]) continue;
		if (dep[at]-dep[to]+1>=tg) return to;
	}
	for (auto to:edge[at]) {
		if (vis[to] or to==par[at]) continue;
		if (!mark[to]) {
			par[to]=at;
			return solve2(to);
		}
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	tg=int(ceil(sqrt(n)));
	for (int i=1;i<=m;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y); deg[x]++;
		edge[y].pb(x); deg[y]++;
	}
	bool ok=solve1();
	if (ok) {
		cout<<1<<endl;
		for (auto i:ans1) cout<<i<<' ';
		cout<<endl;
	}
	else {
		cout<<2<<endl;
		int root;
		for (int i=1;i<=n;i++) 
			if (!vis[i]) {
				root=solve2(i);
				break;
			}
		for (int i=0;;i++) {
			if (ans2[i]==root) {
				cout<<ans2.size()-i<<endl;
				for (int j=i;j<ans2.size();j++) cout<<ans2[j]<<' ';
				cout<<endl;
				break;
			}
		}
	}
}

