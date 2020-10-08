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

const int N=5e5+1;
int n,m,d[N],c[N];
bool vis[N];
vii edge[N];

void bfs() {
	memset(d,-1,sizeof(d)); d[n]=0;
	memset(c,-1,sizeof(c)); c[n]=0;
	queue<int> q; q.push(n);
	while (q.size()) {
		int at=q.front(); q.pop();
		for (auto [from,t]:edge[at]) if (d[from]==-1) {
			if (c[from]==-1) c[from]=t^1;
			else if (c[from]==t) d[from]=d[at]+1,q.push(from);
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=0;i<m;i++) {
		int x,y,t; cin>>x>>y>>t;
		if (x!=y) edge[y].pb(mp(x,t));
	}
	bfs();
	cout<<d[1]<<endl;
	for (int i=1;i<=n;i++) cout<<(c[i]==-1?0:c[i]);
	cout<<endl;
}
