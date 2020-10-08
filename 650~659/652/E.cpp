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

	int n,m; cin>>n>>m;
	vi w(n+1),cnt(n+1),x(m+1),y(m+1),food,ans;
	vector<bool> visf(n+1),visc(m+1);
	vvi cus(n+1);
	for (int i=1;i<=n;i++) cin>>w[i];
	for (int i=1;i<=m;i++) {
		cin>>x[i]>>y[i];
		cus[x[i]].pb(i);
		cus[y[i]].pb(i);
	}
	for (int i=1;i<=n;i++) cnt[i]=cus[i].size();
	priority_queue<pii> pq;
	for (int i=1;i<=n;i++) if (w[i]>=cnt[i]) pq.push(mp(w[i]-cnt[i],i));	
	while (1) {
		while (pq.size() and visf[pq.top().se]) pq.pop();
		if (pq.empty()) break;
		int id=pq.top().se; pq.pop();
		visf[id]=1; food.pb(id);
		for (auto i:cus[id]) {
			if (visc[i]) continue;
			visc[i]=1;
			int id2=(x[i]==id?y[i]:x[i]);
			if (!visf[id2]) {
				cnt[id2]--;
				if (cnt[id2]<=w[id2]) pq.push(mp(w[id2]-cnt[id2],id2));
			}
		}
	}
	int ok=1;
	for (int i=1;i<=n;i++) if (!visf[i]) ok=0;
	if (!ok) cout<<"DEAD"<<endl;
	else {
		for (int i=1;i<=m;i++) visc[i]=0;
		for (auto i:food) 
			for (auto j:cus[i]) 
				if (!visc[j]) ans.pb(j),visc[j]=1;
		cout<<"ALIVE"<<endl;
		for (int i=m-1;i>=0;i--) cout<<ans[i]<<' ';
		cout<<endl;
	}
}

