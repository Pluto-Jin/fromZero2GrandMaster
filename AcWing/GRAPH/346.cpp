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

const int N=6001;
int n,fa[N],cnt[N];
struct bian{
	int x,y,w;
	bool operator<(const bian& tmp) const {
		return w<tmp.w;
	}
} edge[N];
int gf(int x) {return fa[x]==x?x:fa[x]=gf(fa[x]);}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<n;i++) {
			int x,y,w; cin>>x>>y>>w;
			edge[i]={x,y,w};
		}
		sort(edge+1,edge+n);
		for (int i=1;i<=n;i++) fa[i]=i,cnt[i]=1;
		int ans=0;
		for (int i=1;i<n;i++) {
			auto [x,y,w]=edge[i];
			int a=gf(x),b=gf(y);
			ans+=(w+1)*(cnt[a]*cnt[b]-1);
			fa[b]=a,cnt[a]+=cnt[b];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
