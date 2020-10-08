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
vii edge[N];
ll a,b;
int n;

int dfs(int at=1,int par=-1) {
	int cnt=1;
	for (auto [to,w]:edge[at]) if (to!=par) {
		int x=dfs(to,at),y=n-x;
		a+=x%2*w;
		b+=1ll*w*min(x,y);
		cnt+=x;
	}
	return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n;
		n*=2;
		a=b=0;
		for (int i=1;i<=n;i++) edge[i].resize(0);
		for (int i=1;i<n;i++) {
			int x,y,w; cin>>x>>y>>w;
			edge[x].pb(mp(y,w));
			edge[y].pb(mp(x,w));
		}
		dfs();
		cout<<a<<' '<<b<<endl;
	}
}

