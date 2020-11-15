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

const int N=1e4+1;
int n,w,h,tot;
ll lx[N<<1];
struct st{
	ll x,y,c;
	bool operator<(const st &tmp) const {
		return y<tmp.y;
	}
} a[N<<1];

int id(ll x) {return lower_bound(lx,lx+tot,x)-lx;}

struct node{
	ll v,tg;
} t[N<<3];

void mark(int x,ll c) {t[x].v+=c;t[x].tg+=c;}
void down(int x) {ll &c=t[x].tg;mark(lch,c),mark(rch,c);c=0;}
void up(int x) {t[x].v=max(t[lch].v,t[rch].v);}

void update(int L,int R,ll v,int x=1,int l=1,int r=tot) {
	if (L<=l and r<=R) {
		mark(x,v);
	} else {
		down(x);
		if (L<=mid) update(L,R,v,lch,l,mid);
		if (mid+1<=R) update(L,R,v,rch,mid+1,r);
		up(x);
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	while (!cin.eof()) {
		memset(t,0,sizeof t);
		cin>>n>>w>>h;
		for (int i=0;i<n;i++) {
			ll x,y,c; cin>>x>>y>>c;
			a[i]={x,y,c},a[n+i]={x,y+h-1,-c};
			lx[i]=x,lx[i+n]=x+w-1;
		}
		sort(a,a+2*n);
		sort(lx,lx+2*n);
		tot=unique(lx,lx+2*n)-lx;

		ll ans=0;
		for (int i=0;i<2*n;i++) {
			auto [x,y,c]=a[i];
			update(id(x),id(x+w-1),c);
			ans=max(ans,t[1].v);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
