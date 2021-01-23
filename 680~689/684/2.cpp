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

const int N=1e5+1;
int n,m,k,d[N],bad[N];
vi edge[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>m>>k;
		for (int i=1;i<=n;i++) edge[i].resize(0),bad[i]=d[i]=0;
		for (int i=0;i<m;i++) {
			int x,y; cin>>x>>y;
			edge[x].pb(y),edge[y].pb(x);
			d[x]++,d[y]++;
		}
		for (int i=1;i<=n;i++) sort(edge[i].begin(),edge[i].end());
		if (k>sqrt(2*m)+1) {
			cout<<-1<<endl;
			continue;
		}
		set<pii> s;
		for (int i=1;i<=n;i++) s.emplace(d[i],i);
		vi cand;
		int cnt=0;
		while (s.size()) {
			auto [deg,at]=*s.begin(); if (deg>=k) break;
			s.erase({deg,at}); bad[at]=++cnt;
			if (deg==k-1) cand.pb(at);
			for (auto to:edge[at]) if (!bad[to])
				s.erase({d[to],to}),s.insert({--d[to],to});
		}
		if (s.size()) {
			cout<<1<<' '<<s.size()<<endl;
			for (auto [deg,at]:s) cout<<at<<' ';
			cout<<endl;
		} else {
			int ok=0;
			for (auto at:cand) {
				vi tmp; tmp.pb(at);
				for (auto to:edge[at]) if (bad[to]>bad[at]) tmp.pb(to);	
				if (tmp.size()==k) {
					int okk=1;
					for (int i=0;okk and i<k;i++) for (int j=i+1;okk and j<k;j++) 
						if (!binary_search(edge[tmp[i]].begin(),edge[tmp[i]].end(),tmp[j])) okk=0;
					if (okk) {
						cout<<2<<endl;
						for (auto i:tmp) cout<<i<<' ';
						cout<<endl; ok=1; break;
					}
				}
				bad[at]=0;
			}
			if (!ok) cout<<-1<<endl;
		}
	}
	
	return 0;
}
