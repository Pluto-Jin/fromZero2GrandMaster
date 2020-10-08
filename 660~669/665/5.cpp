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

const int N=1e6+1;
int fen[N];
void update(int x,int v){for(;x<=1e6;x+=x&-x)fen[x]+=v;}
int query(int x){int res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}
int query(int l,int r){return query(r)-query(l-1);}
vi rin[N],rout[N];
int sll[N],slr[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	ll ans=1;
	for (int i=0;i<n;i++) {
		int y,l,r; cin>>y>>l>>r;
		if (l==0 and r==1e6) ans++;
		rin[l].pb(y); rout[r].pb(y);
	}
	for (int i=0;i<m;i++) {
		int x,l,r; cin>>x>>l>>r;
		if (l==0 and r==1e6) ans++;
		sll[x]=l; slr[x]=r;
	}
	for (int i=0;i<=1e6;i++) {
		for (auto j:rin[i]) update(j,1);
		if (sll[i] or slr[i]) ans+=query(sll[i],slr[i]);
		for (auto j:rout[i]) update(j,-1);
	}
	cout<<ans<<endl;
}

