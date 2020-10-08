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

const int N=1001;
int n,dep[N],fa[N],mdep;
vi edge[N],ndep[N];

void dfs(int at,int d=0,int par=-1) {
	dep[at]=d; mdep=max(mdep,d);
	ndep[d].pb(at);
	fa[at]=par;
	for (auto to:edge[at]) if (to!=par) dfs(to,d+1,at);
}
pii query(int d,int excl=0) {
	int node,dis;
	if (d==-1) {
		cout<<'?'<<' '<<n<<' ';
		for (int i=1;i<=n;i++) cout<<i<<' '; 
	} else {
		cout<<'?'<<' '<<ndep[d].size()-!!excl<<' ';
		for (auto i:ndep[d]) if (i!=excl) cout<<i<<' ';
	}
	cout<<endl; cout.flush();
	cin>>node>>dis;
	return mp(node,dis);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<n;i++) {
			int x,y; cin>>x>>y;
			edge[x].pb(y);
			edge[y].pb(x);
		}	
		pii pir=query(-1);
		int rt=pir.fi,len=pir.se;
		dfs(rt);

		int ans1,ans2=0,lo=(len+1)/2-1,hi=min(mdep,len)+1;
		while (lo<hi-1) {
			int mid=(lo+hi)/2;
			pir=query(mid);
			if (pir.se>len) hi=mid;
			else ans2=pir.fi,lo=mid;
		}
		int tmp=ans2;
		while (dep[tmp]!=len-lo) tmp=fa[tmp];

		if (lo==len) ans1=rt;
		else ans1=query(len-lo,tmp).fi;

		cout<<'!'<<' '<<ans1<<' '<<ans2<<endl;
		cout.flush();
		string s; cin>>s;
		
		for (int i=0;i<=n;i++) edge[i].resize(0),ndep[i].resize(0);
		mdep=0;
	}
}

