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

const int N=5e5+1;
int n;
struct node{
	int ma,pre,suf,sum;
	node():ma(-1e9),pre(-1e9),suf(-1e9),sum(-1e9){} 
} t[N<<2];

void merge(node &x,node &l,node &r) {
	x.sum=max((int)-1e9,l.sum+r.sum);	
	x.pre=max(l.pre,l.sum+r.pre); 
	x.suf=max(r.suf,r.sum+l.suf); 
	x.ma=max(l.ma,r.ma),x.ma=max(x.ma,l.suf+r.pre); 
}

void update(int p,int v,int x=1,int l=1,int r=n) {
	if (l==r) {
		t[x].ma=t[x].pre=t[x].suf=t[x].sum=v;
		return;
	}
	if (mid>=p) update(p,v,lch,l,mid);
	if (mid+1<=p) update(p,v,rch,mid+1,r);
	merge(t[x],t[lch],t[rch]);
}

node query(int L,int R,int x=1,int l=1,int r=n) {
	if (L<=l and r<=R) return t[x];
	node a,b,res;
	if (mid>=L) a=query(L,R,lch,l,mid);
	if (mid+1<=R) b=query(L,R,rch,mid+1,r);
	merge(res,a,b);
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int m; cin>>n>>m;
	for (int i=1;i<=n;i++) {
		int x; cin>>x;
		update(i,x);
	}
	while (m--) {
		int a,x,y; cin>>a>>x>>y;
		if (a==1) {
			if (x>y) swap(x,y);
			cout<<query(x,y).ma<<endl;
		}
		if (a==2) update(x,y);
	}
	
	return 0;
}
