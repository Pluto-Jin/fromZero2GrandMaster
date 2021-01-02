#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define eb emplace_back
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;
typedef std::vector<std::vector<int>> vvi;

using namespace std;

template<class T,class T2>
inline bool chkmax(T &x,const T2 &y){return x<y?(x=y,1):0;}
template<class T,class T2>
inline bool chkmin(T &x,const T2 &y){return x>y?(x=y,1):0;}

const int N=1e5+1;
ll n,m,h[N],na[N],nb[N],to[N][20];
ll a[N][20],b[N][20];
set<pll> s;

pll solve(ll i,ll k) {
	ll x=0,y=0,cur=i;
	for (int j=19;~j;j--) if (to[cur][j] and x+a[cur][j]+y+b[cur][j]<=k)
	   	x+=a[cur][j],y+=b[cur][j],cur=to[cur][j];
	return {x,y};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<=n;i++) cin>>h[i],s.emplace(h[i],i);
	for (int i=1;i<n;i++) {
		s.erase({h[i],i});
		auto p=s.lower_bound({h[i],i}),q=p;
		vector<tuple<ll,ll,int>> tmp; 
		if (p!=s.end()) {
			tmp.eb(p->fi-h[i],p->fi,p->se); 
			if (++p!=s.end()) tmp.eb(p->fi-h[i],p->fi,p->se);
		}
		if (q!=s.begin()) {
			--q,tmp.eb(h[i]-q->fi,q->fi,q->se);
			if (q!=s.begin()) --q,tmp.eb(h[i]-q->fi,q->fi,q->se);
		}
		sort(tmp.begin(),tmp.end());
		nb[i]=get<2>(tmp[0]);
		if (tmp.size()>1) na[i]=get<2>(tmp[1]);
	}
	for (int i=0;i<20;i++) for (int j=1;j<n-1;j++) {
		if (i>1) to[j][i]=to[to[j][i-1]][i-1];
		else if (i==1) to[j][1]=nb[to[j][0]];
		else to[j][0]=na[j];
	}
	for (int i=0;i<20;i++) for (int j=1;j<n-1;j++) if (to[j][i]) {
		if (i>1) {
			a[j][i]=a[j][i-1]+a[to[j][i-1]][i-1];
			b[j][i]=b[j][i-1]+b[to[j][i-1]][i-1];
		} else if (i==1) {
			a[j][1]=a[j][0];
			b[j][1]=abs(h[to[j][1]]-h[to[j][0]]);
		} else { 
			a[j][0]=abs(h[to[j][0]]-h[j]);
			b[j][0]=0;
		}
	}
	ll k; cin>>k;
	int id=-1;
	double res=1e18;
	for (int i=1;i<=n;i++) {
		auto [x,y]=solve(i,k);
		if (!x and !y) continue;
		double cur=y?1.0*x/y:1e17;
		if (cur<res or cur==res and h[i]>h[id]) res=cur,id=i;
	}
	if (id==-1) {
		ll ma=0;
		for (int i=1;i<=n;i++) if (chkmax(ma,h[i])) id=i;
	}
	cout<<id<<endl;
	cin>>m;
	for (int i=0;i<m;i++) {
		ll aa,bb; cin>>aa>>bb;
		auto [x,y]=solve(aa,bb);
		cout<<x<<' '<<y<<endl;
	}
	return 0;
}
