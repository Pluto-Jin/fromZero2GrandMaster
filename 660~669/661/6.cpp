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

struct node {int to,w,c;};

const int N=2e5+1;
int n;
ll s,sum;
vector<node> edge[N];

auto cmp=[](const pii &a, const pii &b){
	return (a.fi+1)/2*1ll*a.se<(b.fi+1)/2*1ll*b.se;
};
priority_queue<pii,vii,decltype(cmp)> pq1(cmp),pq2(cmp);

int dfs(int at=1,int par=-1) {
	int res=0;
	for (auto [to,w,c]:edge[at]) if (to!=par) {
		int tmp=dfs(to,at);
		if (c==1) pq1.push(mp(w,tmp));
		else pq2.push(mp(w,tmp));
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
			int x,y,w,c; cin>>x>>y>>w>>c;
			edge[x].pb({y,w,c});
			edge[y].pb({x,w,c});
		}
		dfs();
		vector<ll> c1,c2;
		c1.pb(0); c2.pb(0);
		while (pq1.size() and c1.back()<sum-s or pq2.size() and c2.back()<sum-s) {
			if (pq1.size() and c1.back()<sum-s) {
				auto [w,cnt]=pq1.top(); pq1.pop();
				if (w/2) pq1.push(mp(w/2,cnt));
				c1.pb(c1.back()+1ll*(w+1)/2*cnt);
			}
			if (pq2.size() and c2.back()<sum-s) {
				auto [w,cnt]=pq2.top(); pq2.pop();
				if (w/2) pq2.push(mp(w/2,cnt));
				c2.pb(c2.back()+1ll*(w+1)/2*cnt);
			}
		}
		while (pq1.size()) pq1.pop();
		while (pq2.size()) pq2.pop();

		int ans=1e9;
		for (int i=0;i<c1.size();i++) {
			if (c2.back()+c1[i]<sum-s) continue;
			if (c1[i]>=sum-s) {ans=min(ans,i);break;}
			int lo=lower_bound(c2.begin(),c2.end(),sum-s-c1[i])-c2.begin();
			ans=min(ans,i+lo*2);
		}
		cout<<ans<<endl;
	}
}

