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
int n,m,k,sz=1e6,bg,fa[N],dep[N],span[N];
vi edge[N],dtree;

void dfs(int at=1,int par=1,int d=1) {
	dtree.pb(at);
	dep[at]=d; fa[at]=par;
	for (auto to:edge[at]) {
		if (to==par) continue;
		if (dep[to]) {
			if (dep[at]>dep[to] and dep[at]-dep[to]+1<sz) 
				bg=at,sz=dep[at]-dep[to]+1;
		} else dfs(to,at,d+1);
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m>>k;
	for (int i=0;i<m;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y);
		edge[y].pb(x);
	}
	dfs();
	if (m==n-1) {
		cout<<1<<endl;
		for (int i=0,j=n-1;i<(k+1)/2;j--) {
			int at=dtree[j];
			if (!span[at]) cout<<at<<' ',i++,span[at]=1,span[fa[at]]=1;
		}
		cout<<endl;
	}
	else if (sz<=k) {
		cout<<2<<endl<<sz<<endl;
		for (int i=0;i<sz;i++) cout<<bg<<' ',bg=fa[bg];
		cout<<endl;
	} else {
		cout<<1<<endl;
		for (int i=0;i<(k+1)/2;i++) cout<<bg<<' ',bg=fa[fa[bg]]; 
		cout<<endl;
	}
} 

