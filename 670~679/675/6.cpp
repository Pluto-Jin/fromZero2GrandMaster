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

const int N=1e5+1,MOD=1e9+7;
int n,a[N],res[100];
map<int,int> last;
bool npr[N<<1];
vi pr;
struct node {
	int cnt[100];
	vii pp;
	vi pre;
} t[N<<2];

#define mid (l+r>>1)
#define lch (x<<1)
#define rch (x<<1|1)

void up(node &tmp,node &x,node &y) {
	for (int i=0;i<pr.size();i++) tmp.cnt[i]=max(x.cnt[i],y.cnt[i]);
	tmp.pp.resize(x.pp.size()+y.pp.size());
	merge(x.pp.begin(),x.pp.end(),y.pp.begin(),y.pp.end(),tmp.pp.begin());
	tmp.pre.resize(tmp.pp.size());
	for (int i=0;i<tmp.pre.size();i++) tmp.pre[i]=1ll*tmp.pp[i].se*(i?tmp.pre[i-1]:1)%MOD;
}
void up(int x) {up(t[x],t[lch],t[rch]);}

void build(int x=1,int l=1,int r=n) {
	if (l==r) {
		for (int i=0;i<pr.size();i++) {
			t[x].cnt[i]=0;
			while (a[l]%pr[i]==0) t[x].cnt[i]++,a[l]/=pr[i];
		}
		if (a[l]!=1) t[x].pp.pb(mp(last[a[l]],a[l])),t[x].pre.pb(a[l]),last[a[l]]=l;
	}
	else build(lch,l,mid),build(rch,mid+1,r),up(x);
}

int query(int L,int R,int x=1,int l=1,int r=n) {
	if (L<=l and r<=R) {
		for (int i=0;i<pr.size();i++) res[i]=max(res[i],t[x].cnt[i]);	
		int p=lower_bound(t[x].pp.begin(),t[x].pp.end(),mp(L,0))-t[x].pp.begin();
		return p?t[x].pre[p-1]:1;
	} else {
		ll res=1;
		if (mid>=L) res*=query(L,R,lch,l,mid);
		if (mid+1<=R) res*=query(L,R,rch,mid+1,r);
		return res%MOD;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];

	for (int i=2;i<sqrt(2e5);i++) if (!npr[i]) {
		pr.pb(i);
		for (int j=i+i;j<N*2;j+=i) npr[j]=1;
	}
	build();

	int q; cin>>q;
	ll ans=0;
	while (q--) {
		int x,y; cin>>x>>y;
		x=(ans+x)%n+1,y=(ans+y)%n+1;
		if (x>y) swap(x,y);
		memset(res,0,sizeof res);
		ans=query(x,y);
		for (int i=0;i<pr.size();i++) for (int j=0;j<res[i];j++) ans=ans*pr[i]%MOD;
		cout<<ans<<endl;
	}	
	
	return 0;
}
