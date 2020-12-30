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

const int N=1<<20;
int n,k,ma=N-1,a[200001];
struct node {
	ll v,tg,len;
} t[N<<2];

void mark(int x,ll v) {t[x].v+=v*t[x].len;t[x].tg+=v;}
void down(int x) {ll &v=t[x].tg;mark(lch,v),mark(rch,v);v=0;}
void up(node &x,node &l,node &r) {x.v=l.v+r.v;}
void up(int x) {up(t[x],t[lch],t[rch]);}

void build(int x=1,int l=1,int r=ma) {
	if (l==r) t[x].len=1;
	else build(lch,l,mid),build(rch,mid+1,r),t[x].len=t[lch].len+t[rch].len;
}

void update(int L,int R,ll v,int x=1,int l=1,int r=ma) {
	if (L<=l and r<=R) mark(x,v);
	else { 
		down(x);
		if (mid>=L) update(L,R,v,lch,l,mid);
		if (mid+1<=R) update(L,R,v,rch,mid+1,r);
		up(x);
	}
}

int query(ll cnt,int x=1,int l=1,int r=ma) {
	if (l==r) return l;
	else { 
		down(x);
		if (t[lch].v>=cnt) return query(cnt,lch,l,mid);
		else return query(cnt-t[lch].v,rch,mid+1,r);
	}
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<>());
	build();
	ll sum=1,ans=1e9;
	for (int i=1;i<=n;i++) {
		sum+=a[i]-2;
		int mi;
		if (i==1) mi=0;
		else mi=query(1);
		update(mi+2,mi+1+a[i]/2,2);
		if (mi) update(mi,mi,-1);
		if (a[i]%2==0) update(mi+1+a[i]/2,mi+1+a[i]/2,-1);
		if (sum>=k) chkmin(ans,query(k));
	}
	if (sum<k) cout<<-1<<endl;
	else cout<<ans<<endl;
	
	return 0;
}
