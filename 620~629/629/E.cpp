#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long long ll;

const int N=2e5+1;
vi edge[N];
int par[N],dep[N],tin[N],tout[N],t;


bool query(int n,vii ar) {
	for (int i=1;i<n;i++) {
		if (ar[i].se==1) return true;
		ar[i].se=par[ar[i].se];
		ar[i].fi=dep[ar[i].se];
		if (tin[ar[i].se]>tout[ar[i-1].se] or tout[ar[i].se]<tin[ar[i-1].se])
			return false;
	}
	return true;
}
void dfs(int root,int d) {
	tin[root]=t++;
	for (int i:edge[root]) {
		if (par[i]) continue;
		par[i]=root;
		dep[i]=d+1;
		dfs(i,d+1);
	}
	tout[root]=t++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y); edge[y].pb(x);
	}
	par[1]=-1;
	dfs(1,0);
	for (int i=0;i<m;i++) {
		int x; cin>>x;
		vii ar(x);
		for (int j=0;j<x;j++) {
			int t; cin>>t;
			ar[j]=mp(dep[t],t);
		}
		sort(ar.begin(),ar.end());
		reverse(ar.begin(),ar.end());
		cout<<(query(x,ar)?"YES":"NO")<<endl;
	}
}

