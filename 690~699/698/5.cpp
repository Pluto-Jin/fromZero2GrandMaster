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
	int v,tg,len;
} t[N<<2]; 
int n,a[N]; 
pii b[N];

void mark(int x,int v) {t[x].v=t[x].len*(v-1);t[x].tg=v;}
void down(int x) {if(int &v=t[x].tg;v) mark(lch,v),mark(rch,v),v=0;} //if (v)
void up(node &x,node &l,node &r) {
	x.v=l.v+r.v;
	x.len=l.len+r.len;
}
void up(int x) {up(t[x],t[lch],t[rch]);}

void build(int x=1,int l=1,int r=n) {
	if (l==r) t[x]={a[l],0,1};
	else build(lch,l,mid),build(rch,mid+1,r),up(x);
}

void update(int L,int R,int v,int x=1,int l=1,int r=n) { //int L,int R
	if (L<=l and r<=R) mark(x,v);
	else {
		down(x);
		if (mid>=L) update(L,R,v,lch,l,mid); //if (mid>=L) L,R
		if (mid+1<=R) update(L,R,v,rch,mid+1,r); //if (mid+1<=R) L,R
		up(x);
	}
}

node query(int L,int R,int x=1,int l=1,int r=n) {
	if (L<=l and r<=R) return t[x];
	else { 
		down(x);
		node a,b,res; a=b={0,0,0};
		if (mid>=L) a=query(L,R,lch,l,mid);
		if (mid+1<=R) b=query(L,R,rch,mid+1,r);
		up(res,a,b); return res;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int tc; cin>>tc;
	while (tc--) {
		int q; cin>>n>>q;
		string k,s; cin>>k>>s;
		for (int i=1;i<=q;i++) cin>>b[i].fi>>b[i].se;
		reverse(b+1,b+q+1);
		for (int i=0;i<n;i++) a[i+1]=s[i]-'0';
		for (int i=1;i<=n<<2;i++) t[i]={0,0,0};
		build();
		int ok=1;
		for (int i=1;ok and i<=q;i++) {
			auto [l,r]=b[i];
			auto tmp=query(l,r);
			if (tmp.len-tmp.v>tmp.v) update(l,r,1);
			else if (tmp.len-tmp.v<tmp.v) update(l,r,2);
			else ok=0;
		}
		for (int i=1;ok and i<=n;i++) if (query(i,i).v!=k[i-1]-'0') ok=0;
		cout<<(ok?"YES":"NO")<<endl;
	}
	
	return 0;
}
