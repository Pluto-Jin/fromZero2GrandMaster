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

const int N=1e5+1;
int n,a[N],trie[N*31][2],ind;
vii edge[N];

void insert(int tmp) {
	int p=0;
	for (int i=30;~i;i--) {
		int &x=trie[p][tmp>>i&1];
		if (!x) x=++ind;
		p=x;
	}
}

int query(int tmp) {
	int p=0,res=0;
	for (int i=30;~i;i--) {
		int &x=trie[p][!(tmp>>i&1)];
		if (x) res|=1<<i,p=x;
		else p=trie[p][tmp>>i&1];
	}
	return res;
}

void dfs(int at=1,int par=-1) {
	for (auto [to,w]:edge[at]) if (to!=par) {
		a[to]=a[at]^w;
		dfs(to,at);
	}	
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<n;i++) {
		int x,y,w; cin>>x>>y>>w;
		edge[++x].pb(mp(++y,w));
		edge[y].pb(mp(x,w));
	}
	dfs();
	int ans=0;
	for (int i=1;i<=n;i++) {
		if (i-1) ans=max(ans,query(a[i]));
		insert(a[i]);
	}
	cout<<ans<<endl;
	
	return 0;
}
