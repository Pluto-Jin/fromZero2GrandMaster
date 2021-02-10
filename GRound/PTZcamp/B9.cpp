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

const int N=3e5+1;
int n,k,u[N],v[N],fa[N],d[N];
pii a[N];

int gf(int x) {return fa[x]==x?x:fa[x]=gf(fa[x]);}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>k;
	for (int i=1;i<n;i++) {
		int w; cin>>u[i]>>v[i]>>w;
		a[i]={w,i};
	}
	sort(a+1,a+n);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<n;i++) {
		int x=u[a[i].se],y=v[a[i].se],fx=gf(x),fy=gf(y);
		if (fx>fy) swap(fx,fy);
		fa[fy]=fx,d[fy]=a[i].fi;
	}
	priority_queue<int> pq;
	ll sum=0;
	for (int i=1;i<=n;i++) {
		pq.push(-d[i]),sum+=d[i];
		if (pq.size()>k) sum+=pq.top(),pq.pop();
		cout<<sum<<endl;
	}
	
	return 0;
}
