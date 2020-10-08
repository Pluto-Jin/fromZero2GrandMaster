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
int n,m,vis[N];
vi egde[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>m;
		for (int i=1;i<=n;i++) egde[i].resize(0),vis[i]=0;
		for (int i=0;i<m;i++) {
			int x,y; cin>>x>>y;
			egde[y].pb(x);
		}
		vi ans;
		for (int i=1;i<=n;i++) if (!vis[i]) {
			for (auto j:egde[i]) if (!vis[j]) 
				for (auto k:egde[j]) if (!vis[k]) {
					ans.pb(i); vis[i]=1;	
					goto gg;
				}
			gg:;
		}

		cout<<ans.size()<<endl;
		for (auto i:ans) cout<<i<<' ';
		cout<<endl;
	}
}

