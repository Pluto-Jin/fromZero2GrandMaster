#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pii;

int cmp(pii a, pii b)
{
	if (a.se!=b.se) return a.se<b.se;
	return a.fi<b.fi;
}
int main()
{
	int n;
	cin>>n;
	vector<ll> a,t;
	a.resize(n);
	t.resize(n);
	for (auto &i:a) cin>>i;
	for (auto &i:t) cin>>i;
	
	vector<pii> ar;
	for (int i=0;i<n;i++) {
		ar.pb(mp(t[i],a[i]));
	}
	sort(ar.begin(),ar.end(),cmp);

	priority_queue<pii> pq;
	ll ans=0,sum=0,nb=-1;
	ll tmp=ar[0].se;
	int p=0;
	while (1) {
		while (pq.empty() or nb==tmp) {nb=tmp;sum+=ar[p].fi;pq.push(ar[p++]);if (p>=n) break;tmp=ar[p].se;}
		sum-=pq.top().fi;
		pq.pop();
		ans+=sum;
		nb++;
		if (pq.empty() and p>=n) break;
	}
	cout<<ans<<endl;


}
