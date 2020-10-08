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

const int N=1002;
int mr[4]={1,-1,0,0},mc[4]={0,0,1,-1};
int ar[N][N],vis[N][N];

void dfs(int i, int j) {
	vis[i][j]=1;
	for (int k=0;k<4;k++) {
		int ni=i+mr[k],nj=j+mc[k];
		if (!vis[ni][nj] and ar[ni][nj]==1) dfs(ni,nj);
	}
} 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	for (int i=1;i<=n;i++) {
		string s; cin>>s;
		for (int j=1;j<=m;j++) {
			if (s[j-1]=='.') ar[i][j]=-1;
			else ar[i][j]=1;
		}
	}
	int ec=0,er=0,okk=1;
	for (int i=1;i<=n;i++) {
		int ok=0;
		for (int j=1;j<=m;j++) {
			if (ar[i][j]==1) {
				if (ok and ar[i][j-1]==-1) {
					ok=-1;
					break;
				}
				ok=1;
			} 
		}
		if (ok==-1) okk=0;
		if (!ok) er=1;
	}
	for (int j=1;j<=m;j++) {
		int ok=0;
		for (int i=1;i<=n;i++) {
			if (ar[i][j]==1) {
				if (ok and ar[i-1][j]==-1) {
					ok=-1;
					break;
				}
				ok=1;
			} 
		}
		if (ok==-1) okk=0;
		if (!ok) ec=1;
	}
	if (!okk or ec^er) cout<<-1<<endl;
	else {
		int ans=0;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (vis[i][j] or ar[i][j]==-1) continue;
				dfs(i,j);
				ans++;	
			}
		}
		cout<<ans<<endl;
	}
}

