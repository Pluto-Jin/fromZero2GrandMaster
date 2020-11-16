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
int n,m,a[N],mi[N],ma[N];
bool v1[N],v2[N];
vi e1[N],e2[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=0;i<m;i++) {
		int x,y,z; cin>>x>>y>>z;
		e1[x].pb(y),e2[y].pb(x);
		if (z==2) e2[x].pb(y),e1[y].pb(x); 
	}
	queue<int> q;
	q.push(1); v1[1]=1;
	while (q.size()) {
		int at=q.front(); q.pop();
		for (auto to:e1[at]) if (!v1[to]) {
			v1[to]=1;
			q.push(to);
		}
	}
	q.push(n); v2[n]=1;
	while (q.size()) {
		int at=q.front(); q.pop();
		for (auto to:e2[at]) if (!v2[to]) {
			v2[to]=1;
			q.push(to);
		}
	}
	vii tmp;
	for (int i=1;i<=n;i++) if (v1[i]) tmp.pb(mp(a[i],i));
	sort(tmp.begin(),tmp.end());
	for (auto [w,s]:tmp) if (!mi[s]) {
		queue<int> q; 
		q.push(s); mi[s]=w;
		while (q.size()) {
			int at=q.front(); q.pop();
			for (auto to:e1[at]) if (!mi[to] and v1[to]) {
				mi[to]=w;
				q.push(to);
			}
		}
	}
	tmp.resize(0);
	for (int i=1;i<=n;i++) if (v2[i]) tmp.pb(mp(a[i],i));
	sort(tmp.begin(),tmp.end(),greater<>());
	for (auto [w,s]:tmp) if (!ma[s]) {
		queue<int> q; 
		q.push(s); ma[s]=w;
		while (q.size()) {
			int at=q.front(); q.pop();
			for (auto to:e2[at]) if (!ma[to] and v2[to]) {
				ma[to]=w;
				q.push(to);
			}
		}
	}

	int ans=0;
	for (int i=1;i<=n;i++) if (v1[i] and v2[i]) ans=max(ans,ma[i]-mi[i]);
	cout<<ans<<endl;
	
	return 0;
}
