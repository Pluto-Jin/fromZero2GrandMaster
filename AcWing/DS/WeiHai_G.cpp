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

const int N=5e5+1,KEY=13331,HMOD=1e9+7,MOD=65536;
int n,q,a[N],mi[N],pre[N];

struct node {
	int tg,ma,sh,len;
} t[N<<2];

void mark(int x,int v) {
	void down(int);
	void up(int);
	t[x].tg+=v;t[x].ma+=v;t[x].sh+=1ll*v*pre[t[x].len-1]%HMOD,t[x].sh%=HMOD;
	if (t[x].ma>=MOD) {
		if (t[x].len==1) t[x].ma%=MOD,t[x].sh=t[x].ma;
		else down(x),up(x);
	}
}
void down(int x) {int &v=t[x].tg;if(v) mark(lch,v),mark(rch,v);v=0;}
void up(node &x,node &l,node &r) {
	x.ma=max(l.ma,r.ma);
	x.sh=1ll*l.sh*mi[r.len]%HMOD+r.sh,x.sh%=HMOD;
	x.len=l.len+r.len;
}
void up(int x) {up(t[x],t[lch],t[rch]);}

void build(int x=1,int l=1,int r=n) {
	if (l==r) t[x]={0,a[l],a[l],1};
	else build(lch,l,mid),build(rch,mid+1,r),up(x);
}

void update(int L,int R,int v,int x=1,int l=1,int r=n) {
	if (L<=l and r<=R) mark(x,v);
	else {
		down(x);
		if (mid>=L) update(L,R,v,lch,l,mid);
		if (mid+1<=R) update(L,R,v,rch,mid+1,r);
		up(x);
	}
}

node query(int L,int R,int x=1,int l=1,int r=n) {
	if (L<=l and r<=R) return t[x];
	else {
		down(x);
		node a,b,res; a=b={0,0,0,0};
		if (mid>=L) a=query(L,R,lch,l,mid);
		if (mid+1<=R) b=query(L,R,rch,mid+1,r);
		up(res,a,b); return res;
	}
}

void init() {
	pre[0]=mi[0]=1;
	for (int i=1;i<=n;i++) mi[i]=1ll*mi[i-1]*KEY%HMOD;
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+mi[i],pre[i]%=HMOD;
	build();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	init();
	while (q--) {
		int t; cin>>t;
		if (t==1) {
			int l,r; cin>>l>>r;
			update(l,r,1);
		} else if (t==2) {
			int x,y,len; cin>>x>>y>>len;
			cout<<(query(x,x+len-1).sh==query(y,y+len-1).sh?"yes":"no")<<endl;
		} 

	}

	
	return 0;
}
