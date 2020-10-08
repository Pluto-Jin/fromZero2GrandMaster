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

const int N=2e5+1;
int n,k,rt,lv[N],cnt[N],ans;
vi edge[N];

int dfs(int at=rt,int par=rt) {
	for (auto to:edge[at]) if (to!=par) cnt[at]+=dfs(to,at);
	ans+=cnt[at]/k;
	lv[at]=cnt[at]%k==0&cnt[at]==edge[at].size()-1;
	cnt[at]%=k;
	return lv[at];
}
void dfs2(int at=rt) {
	lv[at]=1;
	int ccnt=0,id=0;
	for (auto to:edge[at]) {
		if (!lv[to]) {
			ccnt++;
			if (cnt[to]+1==k) id=to;
		}
	}
	if (ccnt==1 and id) ans++,dfs2(id);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>k;
		ans=0;
		for (int i=1;i<=n;i++) lv[i]=cnt[i]=0,edge[i].resize(0);
		for (int i=1;i<n;i++) {
			int x,y; cin>>x>>y;
			edge[x].pb(y);
			edge[y].pb(x);
		}
		if (k>=n) cout<<0<<endl;
		else if (k==1) cout<<n-1<<endl;
		else {
			for (int i=1;i<=n;i++) if (edge[i].size()==1) {rt=i;break;}
			dfs();
			dfs2();
			cout<<ans<<endl;
		}	
	}
}

