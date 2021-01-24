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
#include<numeric>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ppf pop_front
#define ppb pop_back
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

//segment tree
#define mid (l+r>>1)
#define lch (x<<1)
#define rch (x<<1|1) 

const int N=2e5+1;
struct node{
	int mi,ma,tg,len;
	ll s;
} t[N<<2]; 
int n,a[N]; 

void mark(int x,int v) {t[x].s=1ll*t[x].len*v;t[x].mi=t[x].ma=t[x].tg=v;}
void down(int x) {if (int &v=t[x].tg;v) mark(lch,v),mark(rch,v),v=0;}
void up(node &x,node &l,node &r) {
	x.mi=min(l.mi,r.mi);
	x.ma=max(l.ma,r.ma);
	x.s=l.s+r.s;
}
void up(int x) {up(t[x],t[lch],t[rch]);}

void build(int x=1,int l=1,int r=n) {
	if (l==r) t[x]={a[l],a[l],0,r-l+1,a[l]};
	else build(lch,l,mid), build(rch,mid+1,r), up(x), t[x].len=t[lch].len+t[rch].len;
}

void update(int L,int R,ll v,int x=1,int l=1,int r=n) { //int L,int R
	if (L<=l and r<=R and t[x].ma<=v) mark(x,v);
	else { 
		down(x);
		if (mid>=L and t[lch].mi<v) update(L,R,v,lch,l,mid); //if (mid>=L) L,R
		if (mid+1<=R and t[rch].mi<v) update(L,R,v,rch,mid+1,r); //if (mid+1<=R) L,R
		up(x);
	}
}

int query(int L,int R,int &tot,int x=1,int l=1,int r=n) {
	if (L<=l and r<=R and t[x].s<=tot) {
		tot-=t[x].s;
		return r-l+1;
	} else { 
		down(x);
		int res=0;
		if (mid>=L and t[lch].mi<=tot) res+=query(L,R,tot,lch,l,mid);
		if (mid+1<=R and t[rch].mi<=tot) res+=query(L,R,tot,rch,mid+1,r);
		return res;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int q; cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	build();
	while (q--) {
		int t,x,y; cin>>t>>x>>y;
		if (t==1) update(1,x,y);
		else cout<<query(x,n,y)<<endl;
	}
	
	return 0;
}
