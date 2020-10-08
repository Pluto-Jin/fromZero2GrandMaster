#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se first
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;

const int N=2e5+5;
vector<int> edge[N];
int col[N],ans[N];
int n;

void dfs(int root,int par) 
{
	for (auto i:edge[root]) {
		if (i==par) continue;
		dfs(i,root);
		if (col[i]>0) col[root]+=col[i];
	}
}

void dfs2(int root,int par,int pv)
{
	ans[root]=col[root]+pv;
	for (auto i:edge[root]) {
		if (i==par) continue;
		dfs2(i,root,max(0,ans[root]-max(0,col[i])));
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>col[i];
		col[i]*=2; col[i]-=1;
	}
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y); edge[y].pb(x);
	}
	dfs(1,-1);
	dfs2(1,-1,0);
	for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<endl;
}
