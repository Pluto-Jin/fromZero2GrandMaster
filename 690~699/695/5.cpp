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

const int N=2e5+1;
int n,a[N],tim,tin[N],tout[N],dif[N];
vi edge[N];
map<int,int> cnt;

map<int,int> dfs(int at=1,int par=-1) {
	tin[at]=++tim;
	map<int,int> res,tmp;
	int ok=0;
	res[a[at]]=1;
	for (auto to:edge[at]) if (to!=par) {
		tmp=dfs(to,at);
		if (tmp.count(a[at])) dif[1]++,dif[tin[to]]--,dif[tout[to]+1]++;
		if (tmp.size()>res.size()) swap(res,tmp);
		for (auto [x,y]:tmp) res[x]+=y;
	}
	tout[at]=tim;
	if (cnt[a[at]]>res[a[at]]) dif[tin[at]]++,dif[tout[at]+1]--;
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		cnt[a[i]]++;
	}
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y),edge[y].pb(x);
	}
	dfs();
	int ans=0;
	for (int i=1;i<=n;i++) if (!(dif[i]+=dif[i-1])) ans++;
	cout<<ans<<endl;
	
	return 0;
}
