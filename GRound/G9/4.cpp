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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vi ar(n),vis(n),ans;
		for (auto &i:ar) cin>>i;
		int cur=0;
		for (int i=0;i<n;i++) {
			for (auto &i:vis) i=0;
			for (auto i:ar) if (i<n) vis[i]=1;	
			for (cur=0;cur<n;cur++) if (!vis[cur]) break;
			if (cur<n) ans.pb(cur),ar[cur]=cur;
			else {
				int tmp; for (tmp=0;ar[tmp]==tmp and tmp<n;tmp++);
				if (tmp==n) break;
				for (int i=0;i<n;i++) if (ar[i]==tmp) {
					ans.pb(i),ans.pb(tmp);
					ar[i]=n,ar[tmp]=tmp;
				}
			}
		}
		cout<<ans.size()<<endl;
		for (auto i:ans) cout<<i+1<<' '; cout<<endl;
	}
}

