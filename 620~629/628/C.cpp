#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef long long ll;

const int N=1e5+1;
vector<pii> edge[N];
int n,ans[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	fill(ans,ans+n+1,-1);
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(mp(y,i));
		edge[y].pb(mp(x,i));
	}
	int ok=0;
	for (int i=1;i<=n;i++) {
		if (edge[i].size()>=3) {
			ans[edge[i][0].se]=0;
			ans[edge[i][1].se]=1;
			ans[edge[i][2].se]=2;
			ok=1;
			break;
		}
	}
	if (!ok) for (int i=0;i<n-1;i++) cout<<i<<endl;
	else {
		int tmp=3;
		for (int i=1;i<n;i++) {
			if (ans[i]==-1) ans[i]=tmp++;
		}
		for (int i=1;i<n;i++) cout<<ans[i]<<endl;
	}
}

