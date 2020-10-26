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

const int N=1e4+5;
int lsh[N<<1],fa[N],d[N],a[N],b[N],c[N],tot;

int gf(int x) {
	if (fa[x]==x) return x;
	int f=gf(fa[x]);
	d[x]^=d[fa[x]];
	return fa[x]=f;
}
int id(int x) {return lower_bound(lsh+1,lsh+tot+1,x)-lsh;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	for (int i=1;i<=m;i++) {
		string s; cin>>a[i]>>b[i]>>s;
		c[i]=s[0]=='o';
		lsh[i]=--a[i],lsh[i+m]=b[i];
	}
	sort(lsh+1,lsh+2*m+1);
	tot=unique(lsh+1,lsh+2*m+1)-lsh-1;
	
	for (int i=1;i<=tot;i++) fa[i]=i;
	for (int i=1;i<=m;i++) {
		int ia=id(a[i]),ib=id(b[i]),x=gf(ia),y=gf(ib);
		if (x!=y) {
			fa[x]=y;
			d[x]^=d[ia]^d[ib]^c[i];
		} else if (d[ia]^d[ib]^c[i]) {
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<m<<endl;
	
	return 0;
}
