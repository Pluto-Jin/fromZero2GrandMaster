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

#define mid ((l+r)>>1)
#define lch (x<<1)
#define rch (x<<1|1)

const int N=1e5+1;
int n,tr[N<<2],a[N];

void up(int x) {tr[x]=min(tr[lch],tr[rch]);}
void update(int id,int v,int x=1,int l=1,int r=n) {
	if (l==r) {tr[x]=v;return;}
	if (mid>=id) update(id,v,lch,l,mid);
	if (mid+1<=id) update(id,v,rch,mid+1,r);
	up(x);
}
int query(int L,int R,int x=1,int l=1,int r=n) {
	if (L>n) return 0;
	if (L<=l and r<=R) return tr[x];
	int res=1e9;
	if (mid>=L) res=min(res,query(L,R,lch,l,mid));
	if (mid+1<=R) res=min(res,query(L,R,rch,mid+1,r));
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<=n;i++) {
		int x; cin>>x;
		if (x!=1) {
			a[1]=1;
			if (query(1,x-1)>query(x,x)) a[x]=1;
		}
		update(x,i);
	}
	for (int i=2;i<=n+1;i++) if (query(1,i-1)>query(i,i)) a[i]=1;
	for (int i=1;i<=n+1;i++) if (!a[i]) {
		cout<<i<<endl;
		return 0;
	}
	cout<<n+2<<endl;
	
	return 0;
}
