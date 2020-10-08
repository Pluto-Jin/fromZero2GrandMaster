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
int n;
ll s,sum;
vii edge[N];
auto cmp=[](const pii &a, const pii &b){
	return (a.fi+1)/2*1ll*a.se<(b.fi+1)/2*1ll*b.se;
};
priority_queue<pii,vii,decltype(cmp)> pq(cmp);

int dfs(int at=1,int par=-1) {
	int res=0;
	for (auto [to,w]:edge[at]) if (to!=par) {
		int tmp=dfs(to,at);
		pq.push(mp(w,tmp));
		sum+=1ll*w*tmp;
		res+=tmp;
	}
	if (at!=1 and edge[at].size()==1) return 1;
	else return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>s;
		sum=0;
		for (int i=1;i<=n;i++) edge[i].resize(0);
		for (int i=1;i<n;i++) {
			int x,y,w; cin>>x>>y>>w;
			edge[x].pb(mp(y,w));
			edge[y].pb(mp(x,w));
		}
		dfs();
		int ans=0;
		while (sum>s) {
			auto [w,cnt]=pq.top(); pq.pop();
			sum-=1ll*(w+1)/2*cnt;
			pq.push(mp(w/2,cnt));
			ans++;
		}
		while (pq.size()) pq.pop();
		cout<<ans<<endl;
	}
}

