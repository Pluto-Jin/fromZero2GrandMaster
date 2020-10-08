#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const int N=5e5+1;
set<int> edge[N];
int tpc[N];
vii ar;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	for (int i=0;i<m;i++) {
		int x,y; cin>>x>>y;
		edge[x].insert(y);
		edge[y].insert(x);
	}
	for (int i=1;i<=n;i++) {
		int x; cin>>x;
		ar.pb(mp(x,i));
	}
	sort(ar.begin(),ar.end());
	int cur=0,ok=1;
	for (auto p:ar) {
		int at=p.se;
		if (p.fi>cur+1 or tpc[at]!=p.fi-1) {
			ok=0;
			break;
		}
		cur=p.fi;
		tpc[at]++;
		for (auto to:edge[at]) {
			if (tpc[to]<tpc[at]-1) {ok=0;break;}
			tpc[to]=tpc[at];
			edge[to].erase(at);
		}
	}
	if (!ok) cout<<-1;
	else for (auto p:ar) cout<<p.se<<' ';
	cout<<endl;
}

