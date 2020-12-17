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
ll t[86500<<2],cnt,m,n,INF=0x3f3f3f3f3f3f3f3f; 
struct oh {
	int a,b,c;
	bool operator<(const oh &tmp) {return a<tmp.a;}
} a[N];

void up(int x) {t[x]=min(t[lch],t[rch]);}


void update(int p,ll v,int x=1,int l=1,int r=n) {
	if (l==r) chkmin(t[x],v);
	else {
		if (mid>=p) update(p,v,lch,l,mid);
		else update(p,v,rch,mid+1,r);
		up(x);
	}
}

ll query(int L,int R,int x=1,int l=1,int r=n) {
	if (L<=l and r<=R) return t[x];
	else {
		ll a,b; a=b=INF;
		if (mid>=L) a=query(L,R,lch,l,mid);
		if (mid+1<=R) b=query(L,R,rch,mid+1,r);
		return min(a,b); 
	}
}
 
void build(int x=1,int l=1,int r=n) {
	memset(t,0x3f,sizeof t);
	update(m-1,0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>cnt>>m>>n;
	m+=2,n+=2;
	for (int i=1;i<=cnt;i++) {
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].a+=2, a[i].b+=2;
	}
	sort(a+1,a+cnt+1);
	build();
	for (int i=1;i<=cnt;i++) {
		auto [x,y,z]=a[i];
		update(y,min(INF,query(x-1,y-1)+z));		
	}
	ll ans=query(n,n);
	cout<<(ans==INF?-1:ans)<<endl;
	
	return 0;
}
