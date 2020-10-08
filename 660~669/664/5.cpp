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
int n,m,k,d[N],id[N],ans,qu[10];
vii edge[N],edged[N];
bool vbad[10][10],bad[10][10][10][10];

void dfs(int cur=1) {
	if (cur==k+1) {ans++;return;}
	for (int i=1;i<=cur;i++) if (!vbad[cur][i]) {
		qu[cur]=i;
		int ok=1;
		for (int j=1;j<cur;j++) if (bad[cur][i][j][qu[j]]) ok=0;
		if (ok) dfs(cur+1);
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m>>k;
	for (int i=0;i<m;i++) {
		int x,y,w; cin>>x>>y>>w;
		edge[x].pb(mp(w,y));
		edged[y].pb(mp(w,x));
	}
	for (int i=1;i<=n;i++) {
		d[i]=edge[i].size();
		sort(edge[i].begin(),edge[i].end());
		for (int j=0;j<edge[i].size();j++) id[edge[i][j].fi]=j+1;
	}
	for (int i=1;i<=n;i++) {
		set<pii> st;
		for (auto [w,from]:edged[i]) {
			pii tmp=mp(d[from],id[w]);
			if (st.count(tmp)) vbad[tmp.fi][tmp.se]=1;
			else st.insert(tmp);	
		}
		for (auto [a,b]:st) for (auto [c,d]:st) bad[a][b][c][d]=1;
	}
	dfs();
	cout<<ans<<endl;

	return 0;
}

