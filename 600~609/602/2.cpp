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


//a minimum segment tree
#define mid ((l+r)>>1)
#define lch (x<<1)
#define rch (x<<1|1)

const int N=2e5+1; //
int n,ar[N],tr[N<<2],val[N<<2]; 

void update(int id,int v,int x=1,int l=1,int r=n) {
	tr[x]++;
	if (l==r) {val[x]=v; return;}
	if (mid>=id) update(id,v,lch,l,mid);
	else update(id,v,rch,mid+1,r);	
}

int query(int k,int x=1,int l=1,int r=n) {
	if (l==r) return val[x];
	if (tr[lch]<k) query(k-tr[lch],rch,mid+1,r);
	else query(k,lch,l,mid);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	vii ar(n);
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		ar[i]=mp(-x,i+1);
	}
	int m; cin>>m;
	vector<vii> q(n+1);
	for (int i=0;i<m;i++) {
		int x,y; cin>>x>>y;
		q[x].pb(mp(y,i));
	}

	vi ans(m);
	sort(ar.begin(),ar.end());
	for (int i=0;i<n;i++) {
		update(ar[i].se,-ar[i].fi);
		for (auto [k,id]:q[i+1]) ans[id]=query(k);
	}
	for (auto i:ans) cout<<i<<endl;
}

