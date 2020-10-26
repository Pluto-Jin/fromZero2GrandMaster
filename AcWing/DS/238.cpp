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

const int N=5e5+1;
int fa[N],d[N],sz[N];

int gf(int x) {
	if (fa[x]==x) return x;
	int f=gf(fa[x]);
	d[x]+=d[fa[x]];
	return fa[x]=f;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	for (int i=1;i<=t;i++) fa[i]=i,d[i]=0,sz[i]=1;
	while (t--) {
		char c; int a,b; cin>>c>>a>>b;
		if (c=='M') {
			int x=gf(a),y=gf(b);
			if (x!=y) fa[x]=y,d[x]=sz[y],sz[y]+=sz[x];
		}
		if (c=='C') {
			if (gf(a)!=gf(b)) cout<<-1<<endl;
			else cout<<abs(d[a]-d[b])-1<<endl;
		}
	}
	
	return 0;
}
