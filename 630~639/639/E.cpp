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
int n,m,tin[N],up[N],dw[N];
bool ans[N];
vi edge[N],redge[N];

void topo() {
	queue<int> q;
	for (int i=1;i<=n;i++) if (!tin[i]) q.push(i);
	while (q.size()) {
		int at=q.front(); q.pop();
		for (auto to:edge[at]) if (!--tin[to]) q.push(to);
	}
}

void dfs2(int at, int rt, int rev) {
	if (!rev) {
		up[at]=rt;
		for (auto to:edge[at]) if (!up[to]) dfs2(to,rt,rev);
	} else {
		dw[at]=rt;
		for (auto to:redge[at]) if (!dw[to]) dfs2(to,rt,rev);
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=0;i<m;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y);
		redge[y].pb(x);
		tin[y]++;
	}
	topo();
	int ok=1;
	for (int i=1;i<=n;i++) if (tin[i]) ok=0;
	if (!ok) cout<<-1<<endl;
	else {
		for (int i=1;i<=n;i++) {
			if (!up[i]) dfs2(i,i,0);
			if (!dw[i]) dfs2(i,i,1);
		}
		int cnt=0;
		for (int i=1;i<=n;i++) if (up[i]==i and dw[i]==i) ans[i]=1,cnt++;
		cout<<cnt<<endl;	
		for (int i=1;i<=n;i++) cout<<(ans[i]?'A':'E');
		cout<<endl;
	}
}

