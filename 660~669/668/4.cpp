#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
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
int n,d[N],md;
vi edge[N];

void dfs(int at,int dep=0,int par=-1) {
	d[at]=dep;
	md=max(dep,md);
	for (auto to:edge[at]) if (to!=par) dfs(to,dep+1,at);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int a,b,da,db; cin>>n>>a>>b>>da>>db;
		for (int i=1;i<n;i++) {
			int x,y; cin>>x>>y;
			edge[x].pb(y);
			edge[y].pb(x);
		}
		md=0; dfs(a);
		if (d[b]<=da) cout<<"Alice"<<endl;
		else {
			for (int i=1;i<=n;i++) if (d[i]==md) {
				md=0; dfs(i);
				break;
			}
			if (da*2>=min(md,db)) cout<<"Alice"<<endl;
			else cout<<"Bob"<<endl;
		}
		for (int i=1;i<=n;i++) edge[i].resize(0);
	}
}
