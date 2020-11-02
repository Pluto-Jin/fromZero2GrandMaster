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
#define mp make_pair
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

#define mid (l+r>>1)
#define lch (x<<1)
#define rch (x<<1|1)

const int N=5e5+2;
struct node{
	ll v,d;
} t[N<<2];
ll n,a[N];

void up(node &x,node &l,node &r) {
	x.v=l.v+r.v;
	x.d=__gcd(l.d,r.d);
}
void up(int x) {up(t[x],t[lch],t[rch]);}

void build(int x=1,int l=1,int r=n) {
	if (l==r) t[x]={a[l]-a[l-1],a[l]-a[l-1]};
	else build(lch,l,mid), build(rch,mid+1,r), up(x);
}

void update(int p,ll v,int x=1,int l=1,int r=n) {
	if (l==r) t[x]={t[x].v+v,t[x].d+v};
	else {
		if (mid>=p) update(p,v,lch,l,mid);
		else update(p,v,rch,mid+1,r);
		up(x);
	}
}

node query(int L,int R,int x=1,int l=1,int r=n) {
	if (L<=l and r<=R) return t[x];
	else {
		node a,b,res; a=b={0,0};
		if (mid>=L) a=query(L,R,lch,l,mid);
		if (mid+1<=R) b=query(L,R,rch,mid+1,r);
		up(res,a,b); return res;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int m; cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	build();
	while (m--) {
		char c; cin>>c;
		if (c=='C') {
			ll l,r,x; cin>>l>>r>>x;
			update(l,x); 
			if (r<n) update(r+1,-x);
		} else {
			int l,r; cin>>l>>r;
			cout<<abs(__gcd(query(1,l).v,query(l+1,r).d))<<endl;
		}
	}
	
	return 0;
}
