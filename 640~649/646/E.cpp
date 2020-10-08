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
int n,cst[N],init[N],goal[N];
int vis[N],par[N],unslv[N];
vii ar;
vi edge[N];
ll ans;

void bfs() {
	queue<int> q;
	par[1]=-1;
	q.push(1);
	while (q.size()) {
		int at=q.front(); q.pop();
		for (auto to:edge[at]) {
			if (to==par[at]) continue;
			par[to]=at;
			q.push(to);
		}
	}
}

void bfs2(int nd) {
	queue<int> q;
	q.push(nd);
	int cnt[2]={0,0};
	while (q.size()) {
		int at=q.front(); q.pop();
		if (vis[at]) cnt[unslv[at]>0]+=abs(unslv[at]);
		else {
			if (init[at]!=goal[at]) cnt[init[at]]++;
			vis[at]=1;
			for (auto to:edge[at]) {
				if (to==par[at]) continue;
				q.push(to);
			}
		}
	}
	ans+=1ll*2*cst[nd]*min(cnt[0],cnt[1]);
	unslv[nd]=cnt[1]-cnt[0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>cst[i]>>init[i]>>goal[i];
		ar.pb(mp(cst[i],i));
	}
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y);
		edge[y].pb(x);
	}
	bfs();
	sort(ar.begin(),ar.end());
	for (auto pir:ar) if (!vis[pir.se]) bfs2(pir.se);
	cout<<(unslv[1]?-1:ans)<<endl;
}

