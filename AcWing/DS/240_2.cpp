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
int fa[N<<2];

int gf(int x) {return fa[x]==x?x:fa[x]=gf(fa[x]);}
void merge(int x,int y) {fa[gf(x)]=gf(y);}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,q; cin>>n>>q;
	int ans=0;
	for (int i=1;i<=3*n;i++) fa[i]=i;
	while (q--) {
		int t,x,y; cin>>t>>x>>y;
		if (x>n or y>n or t==2 and x==y) {ans++;continue;}
		if (t==1) {
			if (gf(y+n)==gf(x) or gf(y+n+n)==gf(x)) ans++;
			else merge(x,y),merge(x+n,y+n),merge(x+n+n,y+n+n);
		} else {
			if (gf(x)==gf(y) or gf(x+n)==gf(y)) ans++;
			else merge(x,y+n),merge(x+n,y+n+n),merge(x+n+n,y);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
