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

const int N=1e5+1;
int cnt[N];
priority_queue<pii> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		cnt[x]++;
	}
	for (int i=1;i<=100000;i++) if (cnt[i]) pq.push(mp(cnt[i],i));
	int q; cin>>q;
	for (int i=0;i<q;i++) {
		char c;
		int x; cin>>c>>x;
		if (c=='+') pq.push(mp(++cnt[x],x));
		else pq.push(mp(--cnt[x],x));
		vii tmp;
		while (tmp.size()<3 and pq.size()) {
			auto [a,id]=pq.top();
			if (cnt[id]==a) tmp.pb(pq.top());
			pq.pop();
		}
		int ok=0;
		if (tmp.size()>=1) if (tmp[0].fi>=8) ok=1;
		if (tmp.size()>=2) if (tmp[0].fi>=6 and tmp[1].fi>=2 or tmp[0].fi>=4 and tmp[1].fi>=4) ok=1;
		if (tmp.size()>=3) if (tmp[0].fi>=4 and tmp[1].fi>=2 and tmp[2].fi>=2) ok=1;
		for (auto i:tmp) pq.push(i);
		cout<<(ok?"YES":"NO")<<endl;
	}
}

