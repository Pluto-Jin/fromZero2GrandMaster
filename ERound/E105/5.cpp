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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	map<pii,char> edge;
	set<pii> hui,same;
	while (m--) {
		char c; cin>>c;
		if (c=='+') {
			int x,y; cin>>x>>y>>c;
			edge[{x,y}]=c;
			if (edge.count({y,x})) {
				hui.emplace(min(x,y),max(x,y));
				if (edge[{y,x}]==c) same.emplace(min(x,y),max(x,y));
			}
		} else if (c=='-'){
			int x,y; cin>>x>>y;
			edge.erase({x,y});
			hui.erase({min(x,y),max(x,y)});
			same.erase({min(x,y),max(x,y)});
		} else {
			int x; cin>>x;
			if (x%2) cout<<(hui.size()?"YES":"NO")<<endl;
			else cout<<(same.size()?"YES":"NO")<<endl;
		}
	}
	
	return 0;
}
