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

const int N=5e4+1;
int fa[N],d[N];

int gf(int x) {
	if (fa[x]==x) return x;
	int f=gf(fa[x]);
	if (d[x]==0) d[x]=d[fa[x]];
	else if (d[fa[x]]==1 and d[x]==1) d[x]=-1;
	else if (d[fa[x]]==1 and d[x]==-1) d[x]=0;
	else if (d[fa[x]]==-1 and d[x]==-1) d[x]=1;
	else if (d[fa[x]]==-1 and d[x]==1) d[x]=0;	
	return fa[x]=f;
}

bool merge(int t,int x,int y) {
	int a=gf(x),b=gf(y);
	if (t==1) {
		if (a==b and d[x]!=d[y]) return false;
		if (d[x]==0) d[a]=d[y];
		else if (d[y]==0) d[a]=-d[x];
		else if (d[x]==d[y]) d[a]=0;
		else if (d[x]==1 and d[y]==-1) d[a]=1;
		else if (d[x]==-1 and d[y]==1) d[a]=-1;
	} else {
		if (a==b) if (d[x]==0 and d[y]==-1 or d[y]==0 and d[x]==1 or d[x]==-1 and d[y]==1);
		else return false;
		if (d[x]==1) d[a]=d[y];
		else if (d[y]==-1) d[a]=-d[x];
		else if (d[x]==0 and d[y]==0) d[a]=1;
		else if (d[x]==-1 and d[y]==1) d[a]=0;
		else d[a]=-1;	
	}
	fa[a]=b;
	return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,q; cin>>n>>q;
	int ans=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	while (q--) {
		int t,x,y; cin>>t>>x>>y;
		if (x>n or y>n or t==2 and x==y or !merge(t,x,y)) ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}
