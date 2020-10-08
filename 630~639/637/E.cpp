#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define pf push_front
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const int N=1e4+1,M=1000;
int n,m,d[N],g,r;
ll ans,mi=-1;
int dis[N][M];
bool vis[N][M];

void bfs() {
	deque<pii> q;
	q.pb(mp(0,0));
	while (q.size()) {
		pii tmp=q.front(); q.ppf();
		int at=tmp.fi,mod=tmp.se; 
		if (mi!=-1 and dis[at][mod]>mi) continue;
		if (!mod and d[m-1]-d[at]<=g) {
			mi=dis[at][mod];
			ll res=1ll*mi*(g+r)+d[m-1]-d[at]+mod;
			if (!ans or ans>res) ans=res;
			continue;
		}
		for (int to=at-1;to<=at+1;to+=2) {
			if (to<0) continue;
			int cst=abs(d[to]-d[at])+mod;
			if (cst>g or vis[to][cst%g]) continue;
			vis[to][cst%g]=true;
			if (cst==g) {
				dis[to][0]=dis[at][mod]+1;
				q.pb(mp(to,0));
			} else {
				dis[to][cst%g]=dis[at][mod];
				q.pf(mp(to,cst%g));
			}
		}
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=0;i<m;i++) cin>>d[i];
	sort(d,d+m);
	cin>>g>>r;
	for (int i=1;i<m;i++) if (d[i]-d[i-1]>g) {cout<<-1<<endl; return 0;}

	bfs();
	cout<<(ans?ans:-1)<<endl;
}

